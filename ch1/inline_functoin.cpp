/*
 * Chapter 1-4 Inline function.
 *
 *
 */

#include <iostream>
using namespace std;

/*
 *  Macro example.
 *      pros:
 *          1. better performance for writing codes since a function is Inline.
 *          2. independent from types.
 *              - Not required to indicate types.
 *      cons:
 *          1. difficult to define a complex function.
 *          2. hard to debug macro functions.
 */
#define SQUARE(x) x * x

/*
 * Solution with macro's pros && without cons = inline function.
 */


inline int INLINE_SQUARE(int x){
    // supposed to be marco function when complied.
    return x * x;
}

void lineDivider(){
    cout << endl << endl;
}

int main(){

    /*
     * The following code line will be complied as following
     *  cout << 4 * 4 << endl;
     */
    cout << SQUARE(4) << endl;
    cout << SQUARE(9) << endl;

    lineDivider();


    /*
     *  Calling inline functions.
     */
    cout << INLINE_SQUARE(4) << endl;
    cout << INLINE_SQUARE(9) << endl;


    return 0;
}