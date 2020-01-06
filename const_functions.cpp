/*
 * Chapter 4-1 정보은닉 (Encapsulation) 캡슐화
 *
 *      - 모든 정보(클래스 변수)는 캡슐화가 되어야한다.
 *      - 정보 켭슐화 = 은닉화, 다른 클래스의 맴버를 접근하지 못하도록 한다.
 *      - 하나의 클래스 하나의 목적
 *          - 연관된 모든 정보는 하나의 클래스 캡슐화
 *      - 정답은 없다.
 *
 */

#include <iostream>

using namespace std;

class Point{

private:
    int x;
    int y;

public:
    int getX(){
        return x;
    }

    bool setX(int num){
        if( 0 > num || num > 100){
            cout << "벗어난 범위의 값 전달" <<  endl;
            return false;
        }

        x = num;

        return true;
    }

    int getY(){
        return y;
    }

    void setY(int num){
        y = num;
    }


};

class Rectangle{

public:
    Point upLeft;
    Point lowRight;

    void ShowRecInfo(){
        cout << "좌 상단: " << '[' << upLeft.getX() << ", ";
        cout << upLeft.getY() << ']' << endl;
        cout << "우 하단: " << '[' << lowRight.getX() << ", ";
        cout << lowRight.getY() << ']' << endl << endl;
    }

    void InitMembers(const Point &ul, const Point &lr);


};

void Rectangle:: InitMembers(const Point &ul, const Point &lr) {

    if(ul.getX() > lr.getX())
}

int main(){
    cout << "Encapsulation" << endl;

    Point p1;
    /*
        p1.x = 10;
        p1.y = 20;
    */
    p1.setX(10);
    p1.setY(20);

    Point p2;
    /*
        p2.x = 30;
        p2.y = 30;
    */

    Rectangle rectangle;
    rectangle.upLeft = p1;
    rectangle.lowRight = p2;

    rectangle.ShowRecInfo();


    return 0;
}















