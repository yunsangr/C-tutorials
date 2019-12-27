/*
 * Chapter 2-1 Intro && Boolean
 *
 * 1. const int num = 10;
 *  - the value of num is const.
 * 2. const int * ptr1 = &val1;
 *  - the value of val1 cannot be changed by ptr1.
 * 3. int * const ptr2 = &val2;
 *  - the variable pointed by ptr2 cannot be changed.
 * 4. const int * const ptr3 = &val3;
 *  - combine both constraints from (2) and (3).
 *
 *
 *  Memory Structure.
 *      Data: global variable.
 *          for process.
 *      Stack: Local variable && parameters.
 *          for functions.
 *      Heap: malloc & free
 *          -Dynamically allocate memory.
 *          for runtime.
 *
 *  Call-by-value(variable) vs Call-by-reference(pointer).
 *
 *      -Call-by-value.
 *      Inside function scope, you cannot access data scope.
 *          therefore, it is not possible to change/access
 *          params'value.
 *
 *      void SwapByValue(int num1, int num2){
 *          int temp = num1;
 *          num1 = num2;
 *          num2 = temp;
 *      }
 *      after calling, variable num1 && num2's value remain same.
 *
 *
 *      -Call-by-reference.
 *      You can access/modify the values of params with pointers.
 *      void SwapByRef(int * ptr1, int * ptr2){
 *          int temp = *ptr1;
 *          *ptr1 = *ptr2;
 *          *ptr2 = temp;
 *      }
 *
 *
 */

#include <iostream>
using namespace std;

bool isBiggerThanFive(int num){
    return num > 5;
}

int main(){

    bool isPos = false;
    int num;
    while(!isPos){
        cout << "Input number: ";
        cin >> num;
        isPos = isBiggerThanFive(num);
    }
    cout << "You entered " << num << ",which is bigger than 5!";


    return 0;
}
