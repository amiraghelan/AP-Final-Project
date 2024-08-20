#include <iostream>
#include <stdexcept>

#include "VectorDoublePointer.h"

using namespace std;

int main()
{   
    
        // creates empty vector
    CustomVectorPointer<int> c1;
    cout << "empty vector created" << endl;
    cout << "c1: ";
    c1.print();



     // pushing back 3 values to c1
    c1.pushBack(1);
    c1.pushBack(2);
    c1.pushBack(3);
    cout << "c1 after values 1,2,3 are pushed back" << endl;
    cout << "c1: ";
    c1.print();

    // insertin at index 1 and 0
    c1.insert(1, 17);
    c1.insert(0, 45);
    cout << "c1 after value 17 inserted in index 1 and 45 in index 0" << endl;
    cout << "c1: ";
    c1.print();


    // removing from index 0 and 1
    c1.remove(0);
    c1.remove(1);
    cout << "c1 after values at index 0 and then index 2 is removed" << endl;
    cout << "c1: ";
    c1.print();
    return 0;
}