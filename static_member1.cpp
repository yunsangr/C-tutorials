#include "main.h"
#include <thread>


// public member는 그냥 이렇게 초기화 가능.
int static_demo::public_number = 0;

/*
 *  int static_demo::private_number = 32; (x)
 *  private member는 이렇식으로 접근 불가능.
 */
int static_demo::private_number = static_demo::doubleValue(0);

int main(){
  cout << "static_demo::public_number: " << static_demo::public_number << endl;
  cout << "static_demo::getPrivateStatic(): " << static_demo::getPrivateStatic() << endl;

  static_demo sd;
  static_demo sd1;

  cout << sd.sum(10);


  return 0;
}