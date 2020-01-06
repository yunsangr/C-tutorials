#include <iostream>
#include <thread>
#include <mutex>


static int i = 0;

int main()
{
  std::mutex m;

  std::thread a([&] {
    for (int j = 0; j < 30; ++j)
    {
//      m.lock();
//      std::cout << "  thread A: " << i++ << std::endl;
//      std::cout << "  thread A (j): " << j << std::endl;
      std::cout << j << std::endl;

//      m.unlock();
    }
  });
  std::thread b([&] {
    for (int j = 0; j < 30; ++j)
    {
//      m.lock();
//      std::cout << "thread B: " << i++ << std::endl;
//      std::cout << "thread B (j): " << j << std::endl;
      std::cout << j << std::endl;

//      m.unlock();
    }
  });

  a.join();
  b.join();

  std::cout << "after all i = " << i << std::endl;

  return 0;
}