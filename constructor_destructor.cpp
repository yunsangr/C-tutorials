/*
 * Chapter 4 - 3 Constructor and Destructor
 *
 *
 *
 * 생성자:
 *  - 모든 계체는 한 번의 생성자를 걸친다.
 *  - 생성자도 함수의 일종이므로, 오버로딩이 가능하고
 *    디폴트 값 설정이 가능하다.
 *  - 생성자는 반환형이 없다.
 *  - 디폴트 생성자는 생성자함수가 존재 하지 않을때만 존재한다.
 *    즉, 생성자를 만들었을시, 디폴트 생성자의 역활을 해주는
 *    디폴트 형 생성자를 만들어 주어야 한다.
 *    (오버로딩 사용)
 *  - 생성자의 종류가 3개라면, 오브젝트를 만드는 방법이 3가지라는 뜻이다.
 *  - 디폴트 생성자 (만들어진 생성자 함수 존재하지 않을 떄):
 *    SimpleClass sc1();    (o)
 *    생성자를 만들어 주었을 경우:
 *    SimpleClass sc1();    (x)
 *    SimpleClass sc1;      (o)
 *    SimpleClass sc1(100); (o)
 *
 *
 *  - 생성자 내에서 생성자를 호출하는것도 가능하다.
 *
 *  소멸자:
 *    - 하나의 클라스는 오직 하나의 소멸자만 가질 수 있다.
 *
 *    -
 *      ~ClassName(){
 *        do something here...
 *      }
 */


#include <iostream>

using namespace std;

class Point{
private:
  int x;
  int y;

public:
  Point(const int &xops, const int &ypos){
    cout << "Constructor operated..." << endl;
    x = xops;
    y = ypos;
  };
  int GetX() const{
    return x;
  };
  int GetY() const{
    return y;
  };
  void SetX(int xpos){
    x = xpos;
  };
  void SetY(int ypos){
    y = ypos;
  };
  void displayPoint() const{
    cout << "x: " << x ;
    cout << "  y: " << y << endl << endl;
  }

  ~Point(){
    cout << "Point destructor called" << endl;
  }
};

class Rectangle{
private:
  Point upLeft;
  Point lowRight;

public:

  Rectangle(const int &x1, const int &y1, const int x2, const int &y2)
  :upLeft(x1, y1) , lowRight(x2, y2){
    cout << "Rectangle constructor..." << endl;
  }
  void ShowRecInfo() const {
      upLeft.displayPoint();
      lowRight.displayPoint();
  }

  ~Rectangle(){
    cout << "Rectangle destructor called" << endl;
  }
};

int main(){
    cout << "Chapter 4 - 3 Constructor and Destructor" << endl;

    int x1 = 1;
    int y1 = 3;
    int x2 = 9;
    int y2 = 12;

    Rectangle r = * new Rectangle(x1, y1, x2, y2);
    r.ShowRecInfo();


    return 0;
}















