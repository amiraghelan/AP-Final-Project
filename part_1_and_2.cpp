#include <iostream>
#include <stdexcept>
#include "Vector.h"

using namespace std;

int main()
{

    // creates empty vector
    CustomVector<int> c1;
    cout << "empty vector created" << endl;
    cout << "c1: ";
    c1.print();

    // creates vector with given size and value
    CustomVector<float> c2{5, 2.1f};
    cout << "vector initialized with size and given value" << endl;
    cout << "c2: ";
    c2.print();

    // create empty vector with given size
    CustomVector<float> c3{2};
    cout << "empty vector created with given size " << endl;
    cout << "c3: ";
    c3.print();

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

    // removing from index 0 and 2
    c1.remove(0);
    c1.remove(2);
    cout << "c1 after values at index 0 and then index 2 is removed" << endl;
    cout << "c1: ";
    c1.print();

    // resizing c1 to 6 and filling new indecies with value 7
    c1.resize(6, 7);
    cout << "c1 after resized to 6 and empty indecies filled with value 7" << endl;
    cout << "c1: ";
    c1.print();

    return 0;
}