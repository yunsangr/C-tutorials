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

  th1.join();
  th2.join();
  th3.join();
  th4.join();

  cout << "Number: " << number << endl;


  return 0;
}