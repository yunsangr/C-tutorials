#include "main.h"
#include <thread>
#include <vector>

// public member는 그냥 이렇게 초기화 가능.
int static_demo::public_number = 0;
std::mutex m;
/*
 *  int static_demo::private_number = 32; (x)
 *  private member는 이렇식으로 접근 불가능.
 */
int static_demo::private_number = static_demo::doubleValue(0);

void doWork(){
  static_demo sd2;
  std::lock_guard<std::mutex> lock(m);
  cout << "working in thread, sd2.private_sum(5):  " << sd2.private_sum(5) << endl;
  cout << "working in thread, sd2.public_sum(10):  " << sd2.public_sum(10) << endl;

}

int main(){

  std::vector<std::thread> workers;

//  cout << "static_demo::public_number: " << static_demo::public_number << endl;
//  cout << "static_demo::getPrivateStatic(): " << static_demo::getPrivateStatic() << endl;
//
//  static_demo sd;
//  static_demo sd1;
//
//  cout << sd.private_sum(10) << endl;
//  cout << sd1.private_sum(20) << endl;
//
//  cout << sd.public_sum(3) << endl;
//  cout << sd1.public_sum(29) << endl;


//  std::thread t1(doWork);

  for (int i = 0; i < 10; i++){
    workers.push_back(std::thread(doWork));
  }

  for (int i = 0; i < 10; i++){
    workers[i].join();
  }

//  t1.join();


  return 0;
}