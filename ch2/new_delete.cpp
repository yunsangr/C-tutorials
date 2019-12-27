/*
 *
 *  Chapter 2-5 malloc & free => new & delete
 *
 */

#include <iostream>
using namespace std;



int main(){

    // allocating memory
    int * ptr1 = new int;
    double * ptr2 = new double;
    int * arr1 = new int[3];
    double * arr2 = new double[4];


    // freeing
    delete ptr1;
    delete ptr2;
    delete []arr1;
    delete []arr2;

    return 0;
}