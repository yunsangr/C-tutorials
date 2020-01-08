#include <iostream>
#include <thread>
#include <vector>

std::mutex m;

/*
void worker(int& counter) {
  for (int i = 0; i < 10000; i++) {
    /// 임계 영역 지(critical section)
    m.lock();
    counter += 1;
    m.unlock();
    /// 여기까
  }
}
*/

void worker(int& result) {
  for (int i = 0; i < 10000; i++) {
    // lock 생성 시에 m.lock() 을 실행한다고 보면 된다.
    std::lock_guard<std::mutex> lock(m);
    result += 1;

    // scope 를 빠져 나가면 lock 이 소멸되면서
    // m 을 알아서 unlock 한다.
  }
}

int main() {
  int counter = 0;

  std::vector<std::thread> workers;
  for (int i = 0; i < 4; i++) {
    // 레퍼런스로 전달하려면 ref 함수로 감싸야 한다 (지난 강좌 bind 함수 참조)
    workers.push_back(std::thread(worker, std::ref(counter)));
  }

  for (int i = 0; i < 4; i++) {
    workers[i].join();
  }

  std::cout << "Counter 최종 값 : " << counter << std::endl;
}