#include <thread>
#include <iostream>

using namespace std;

std::mutex mtx;

int number = 10;

void IncreaseNumber(int th_number){
  mtx.lock();
  ++number;
  cout << "Thread " << th_number << endl;
  cout << endl << number << endl;
  mtx.unlock();
}




int main(){

//  IncreaseNumber();r
//  IncreaseNumber();
//  IncreaseNumber();
//  IncreaseNumber();

  thread th1(IncreaseNumber, 1);
  thread th2(IncreaseNumber, 2);
  thread th3(IncreaseNumber, 3);
  thread th4(IncreaseNumber, 4);
  thread th5(IncreaseNumber, 5);
  thread th6(IncreaseNumber, 6);
  thread th7(IncreaseNumber, 7);
  thread th8(IncreaseNumber, 8);

  th1.join();
  th2.join();
  th3.join();
  th4.join();
  th5.join();
  th6.join();
  th7.join();
  th8.join();

  cout << "Number: " << number << endl;


  return 0;
}