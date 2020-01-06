#include <thread>
#include <mutex>
#include <iostream>

std::mutex mtx;

void ThreadFunc(int nID, int& nVal)
{
  for (int i = 0 ; i < 10 ; ++i)
  {
    mtx.lock();
    std::cout << "Value of " << nID << " -> " << nVal << std::endl;
    ++nVal;
    mtx.unlock();
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
}

int main()
{
  int nVal = 0;
  std::thread th1(ThreadFunc, 10, std::ref(nVal));

  std::thread th2(ThreadFunc, 20, std::ref(nVal));

  th1.join();
  th2.join();

  return 0;
}