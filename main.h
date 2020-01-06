#include <iostream>
using namespace std;

class static_demo {
public:
  static int public_number;
  static void setPrivateStatic(int value){
    private_number = value;
  }

  static int getPrivateStatic(){
    return private_number;
  }

  static int doubleValue(int value){
    return value * 2;
  }

  int sum(int value){
    private_number += value;
    return private_number;
  }

private:
  static int private_number;

};