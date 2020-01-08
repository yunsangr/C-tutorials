#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
/*
 *  소스코드 URL: https://modoocode.com/285
 */

namespace ThreadPool {
class ThreadPool {
public:
  ThreadPool(size_t num_threads);
  ~ThreadPool();

  /// job 을 추가한다.
  void EnqueueJob(std::function<void()> job);

private:
  /// 총 Worker 쓰레드의 개수.
  size_t num_threads_;
  /// Worker 쓰레드를 보관하는 벡터.
  std::vector<std::thread> worker_threads_;
  /// 할일들을 보관하는 job 큐.
  std::queue<std::function<void()>> jobs_;
  /// 위의 job 큐를 위한 cv 와 m.
  std::condition_variable cv_job_q_;
  std::mutex m_job_q_;

  /// 모든 쓰레드 종료
  bool stop_all;

  /// Worker 쓰레드
  void WorkerThread();
};


/// ThreadPool 생성자

ThreadPool::ThreadPool(size_t num_threads)
    : num_threads_(num_threads), stop_all(false) {
  /// 쓰레드 갯수 설정 && stop_all = false

  /// Thread vector worker_threads 의 메모리 사이즈 세팅.
  worker_threads_.reserve(num_threads_);

  /// worker_threads vector 에다가 람다식을 삽입 this->WorkerThread();
  for (size_t i = 0; i < num_threads_; ++i) {
    /// 각각의 스레드들에게 작업을 전달.
    worker_threads_.emplace_back([this]() { this->WorkerThread(); });
  }
}

void ThreadPool::WorkerThread() {
  while (true) {

    std::unique_lock<std::mutex> lock(m_job_q_);
    /// 일이 없거나 모든일이 끝날 떄까지 기다렸다가 종료.
    cv_job_q_.wait(lock, [this]() { return !this->jobs_.empty() || stop_all; });
    /// 모든 일이 완료되고 일이 없으면 종료.
    if (stop_all && this->jobs_.empty()) {
      return;
    }

    /// 맨 앞의 job 을 뺀다.
    std::function<void()> job = std::move(jobs_.front());
    jobs_.pop();
    lock.unlock();

    /// 해당 job 을 수행한다 :)
    job();
  }
}

ThreadPool::~ThreadPool() {
  stop_all = true;
  cv_job_q_.notify_all();

  for (auto& t : worker_threads_) {
    t.join();
  }
}

/// 작업을 추가하는 작업.
void ThreadPool::EnqueueJob(std::function<void()> job) {
  if (stop_all) {
    throw std::runtime_error("ThreadPool 사용 중지됨");
  }
  {
//    std::lock_guard<std::mutex> lock(m_job_q_);
    jobs_.push(std::move(job));
  }
  cv_job_q_.notify_one();
}

}  // namespace ThreadPool

void work(int t, int id) {
  /// t초 걸리는 일
  std::thread::id this_id = std::this_thread::get_id();
  printf("%d start, required time: %d, threadID: %d \n", id, t * 3, this_id);
  std::this_thread::sleep_for(std::chrono::seconds(t * 3));
  printf("%d end after %ds, threadID: %d\n", id, t * 3, this_id);
}

int main() {
  ThreadPool::ThreadPool pool(5);

  for (int i = 0; i < 20; i++) {
    /// (1, 0), (2, 1), (3, 2)
    /// (1, 3), (2, 4), (3, 5)
    /// (1, 6), (2, 7), (3, 8)
    /// (1, 9)
    pool.EnqueueJob([i]() { work(i % 3 + 1, i); });
  }
}


/***
 *  Condition Variable
 *
 */

























































