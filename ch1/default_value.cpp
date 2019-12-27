/*
 * Chapter 1-3 default value for params.
 *  - parameters in functions can have default values.
 *  - but the default values must be declared from right to left order.
 *
 *
 */

#include <iostream>
using namespace std;

void func(int x = 0, int y = 0){
    cout << " int x: " << x;
    cout << " int y: " << y << endl;
}

void func1(int x, int y, int z = 10){
    cout << " int x: " << x;
    cout << " int y: " << y;
    cout << " int z: " << z << endl;
}

void lineDivider(){
    cout << endl << endl;
}

int main(){

    func();
    func(10);
    func(10, 20);

    lineDivider();

//    func1(1); cannot call func1 with one single param.
    func1(1,2);
    func1(1, 2, 3);


    return 0;
}