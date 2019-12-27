/*
 * Chapter 2-3 Understanding Reference
 *
 *
 */

#include <iostream>

using namespace std;


void lineDivider(){
    cout << endl << endl;
}


int main(){


    /*
     *
     *  Pointers
     *
     */

    int num = 10;
    int *ptr = &num;

    cout << "num: " << num << endl;
    cout << "*ptr: " << *ptr << endl;
    cout << "&num: " << &num << endl;
    cout << "ptr: " << ptr << endl;

    // increment of num's value by ptr.
    lineDivider();
    ++*ptr; // 10 -> 11

    cout << "num: " << num << endl;
    cout << "*ptr: " << *ptr << endl;
    cout << "&num: " << &num << endl;
    cout << "ptr: " << ptr << endl;


    lineDivider();

    /*
     *
     *  Reference
     *
     */

    int num1 = 2019;
    int &num2 = num1;

    cout <<  "num1: " <<  num1 << endl;
    cout <<  "num2: " <<  num2 << endl;
    cout <<  "&num1: " <<  &num1 << endl;
    cout <<  "&num2: " <<  &num2 << endl;

    num1 = 1920;

    cout <<  "num1: " <<  num1 << endl;
    cout <<  "num2: " <<  num2 << endl;
    cout <<  "&num1: " <<  &num1 << endl;
    cout <<  "&num2: " <<  &num2 << endl;

    num2 = 999;

    cout <<  "num1: " <<  num1 << endl;
    cout <<  "num2: " <<  num2 << endl;
    cout <<  "&num1: " <<  &num1 << endl;
    cout <<  "&num2: " <<  &num2 << endl;

    /*
     *  int &ref = 20; (x)
     *      - No reference for const
     *  int &ref; (x)
     *      - No reference for nothing
     *  int &ref = NULL; (x)
     *      - No reference for Null
     */

    return 0;
}