/*
 * Chapter 2-4 reference and function
 *
 *  Without pointer, it is possible to do call-by-reference with reference type.
 *
 */



#include <iostream>

using namespace std;

void changeByValue(int num){
    cout << "In changeByValue func, num: " << num << endl;
    num = num + 3;
    cout << "In changeByValue func, num: " << num << endl;
}

void changeByPointer(int *num){
    cout << "In changeByPointer func, *num: " << *num << endl;
    *num = *num + 3;
    cout << "In changeByPointer func, *num: " << *num << endl;
}

void changeByRef(int &num){
    cout << "In changeByRef func, &num: " << num << endl;
    num = num + 3;
    cout << "In changeByRef func, &num: " << num << endl;
}

void lineDivider(){
    cout << endl << endl;
}

int & returnRef(int &ref){
    ref++;
    return ref;
}

int main(){

    int num = 2019;

    cout << "num: " << num << endl;
    changeByValue(num);
    cout << "num: " << num << endl;

    lineDivider();

    cout << "num: " << num << endl;
    changeByPointer(&num);

    cout << "num: " << num << endl;

    lineDivider();

    cout << "num: " << num << endl;
    changeByRef(num);
    cout << "num: " << num << endl;

    int num1 = 391;

    cout << "num1: " << num1 << endl;
    int &num2 = returnRef(num1);
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;

    lineDivider();

    int num3 = returnRef(num1);
    cout << "num1: " << num1 << endl;
    cout << "num3: " << num3 << endl;

    num3 = num3 + 100;
    cout << "num1: " << num1 << endl;
    cout << "num3: " << num3 << endl;





    return 0;
}