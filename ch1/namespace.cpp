/*
 * Chapter 1-5 Namespace
 *      Problems:
 *       With duplicated names of functions from different library,
 *       cannot call the function since we cannot distinguish
 *       which functions
 *       we are calling.
 *      Solutions:
 *       Namespace - grouping functions with identifiers.
 *
 */
#include <iostream>
using namespace std;

namespace ns{
    void sayHi(){
        cout << "hello from ns!" << endl;
    }
}

using namespace ns;
//
namespace namespaceA{

    int myage = 10;

    void sayHi(){
        cout << "Hi how are you? :)" << endl;
    }

    void sayBye();

    // we can also have nested namespace like the following below.
    namespace SubOne {
        int num = 3;
    }

    namespace SubTwo {
        int num = 10;
    }
}

namespace namespaceB{

    int myage = 20;

    void sayHi(){
        cout << "Hello babs? :)" << endl;
    }

    void sayBye();

}

// namespace can be divided like the following.
namespace namespaceA{
    int myweight = 86;

    // you can call a function from other namespaces here.
    void sayNamespaceB_Bye(){
        cout << "   sayNamespaceB_Bye() \n";
        sayBye();
        namespaceB::sayBye();
    }
}
// Too much nested namespace.
namespace A{
    namespace B{
        namespace C{
            int num1 = 9341;
            int num2 = 3131;
            void sayHi(){
                cout << "Hello from C in B in A\n";
            }
        }
    }
}

namespace ABC = A::B::C;

void lineDivider(){
    cout << endl << endl;
}

// The following variables are in the global scope.
int globalA = 123;
int globalB = 321;

void GlobalHi(){
    /*
     *  (empty):: <- access the global scope.
     */

    int globalA = 30;
    globalA += 3;
    cout << "globalA: " << globalA << endl;
    cout << "::globalA: " << ::globalA << endl;

    cout << "Hello from the global scope!\n";
}

int main(){

    // :: <- 범위 지정 연산자 (scope resolution operator)
    namespaceA::sayHi();
    cout << "namespaceA::myage is " << namespaceA::myage << endl;
    cout << "namespaceA::myweight is " << namespaceA::myweight << endl;
    namespaceA::sayBye();
    namespaceA::sayNamespaceB_Bye();

    lineDivider();

    namespaceB::sayHi();
    cout << "namespaceB::myage is " << namespaceB::myage << endl;
    namespaceB::sayBye();

    lineDivider();
    //printing sub namespace.
    cout << "namespaceA::SubOne::num " << namespaceA::SubOne::num << endl;
    cout << "namespaceA::SubTwo::num " << namespaceA::SubTwo::num << endl;

    lineDivider();
    ns::sayHi();
    /*
     * With 'using namespace ns',
     * you can just call the function from ns.
     */
    sayHi(); // -> same as ns::sayHi();

    lineDivider();

    A::B::C::sayHi();
    ABC::sayHi(); // -> A::B::C::sayHi()

    lineDivider();
    GlobalHi();

    return 0;
}

/*
 * You can also declare functions outside namespace.
 */
void namespaceA::sayBye() {
    cout << "Good bye from A" << endl;
}

void namespaceB::sayBye() {
    cout << "Good bye from B" << endl;
}