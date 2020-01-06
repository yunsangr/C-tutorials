/*
 * Chapter 404 Class, Array, and this.pointer
 *
 *
 *
 *  this 포인터는 그 값이 결정되어 있지 않은 포인터이다.
 *  왜냐하면 this 포인터는 this가 사용된 객체 자신의 주소값을 정보로 담고 있는 포인터이기 때문이다.
 *
 */

#include <iostream>

using namespace std;

class SoSimple{
private:
  int num;

public:
  SoSimple(int n) : num(n){
    cout << "num=  " << num << ", ";
    cout << "address= " << this << endl;
  }
  void Show(){
    cout << num << endl;
  }
  SoSimple * GetThisPointer(){
    return this;
  }
};

int main(){

  SoSimple s1(100);
  SoSimple * ptr1 = s1.GetThisPointer();
  cout << ptr1 << ", ";
  ptr1->Show();

  SoSimple s2(200);
  SoSimple * ptr2 = s2.GetThisPointer();
  cout << ptr2 << ", ";
  ptr2->Show();



  return 0;
}