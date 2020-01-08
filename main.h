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

  /// helper function for initialization of static variables.
  static int doubleValue(int value){
    return value * 2;
  }

  int private_sum(int value){
    private_number += value;
    return private_number;
  }

  int public_sum(int value){
    public_number += value;
    return public_number;
  }

private:
  static int private_number;

};