#include <iostream>
#include <thread>
using namespace std;

int myAmount = 0;

std::mutex m;

void addMoney(int t_id){
  m.lock();
  ++myAmount;
  cout << "t_id: " << t_id << endl;
  m.unlock();

}

int main(){

  thread t1(addMoney, 1);
  thread t2(addMoney, 2);
  thread t3(addMoney, 3);
  thread t4(addMoney, 4);
  thread t5(addMoney, 5);
  thread t6(addMoney, 6);
  thread t7(addMoney, 7);
  thread t8(addMoney, 8);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
  t7.join();
  t8.join();

  cout << "myAmount: " << myAmount << endl;
  return 0;
}