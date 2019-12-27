/*
 * Chapter 1-2 overloading.
 *  - Overloading functions mean you can define multiple functions
 *    with different number or type of params.
 */


#include <iostream>
using namespace std;

void func(){
    cout << "initial func" << endl;
}

void func(char c){
    cout << "char c: " << c << endl;
}

// overloading with different type.
void func(int x){
    cout << "int x: " << x << endl;
}

// overloading with different number of params.
void func(int x, int y){
    cout << "int x: " << x ;
    cout << "int y: " << y << endl;

}

int main(){

    func();
    func('k');
    func(1);
    func(1, 2);

    return 0;
}