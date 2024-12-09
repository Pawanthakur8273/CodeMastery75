#include <iostream>
using namespace std;

int main() {
    // Pointer to constant data, but the pointer itself is not constant
    const int* dynamicValue = new int(10); 
    // int const* dynamicValue = new int(10); above line and this line both have same meaning
    cout << "Value pointed to by dynamicValue (initial): " << *dynamicValue << endl;
    dynamicValue = new int(20);  // Reassigning the pointer is allowed
    cout << "Value pointed to by dynamicValue (after reassignment): " << *dynamicValue << endl;

    // Constant pointer to modifiable data
    int* const fixedPointer = new int(300); 
    cout << "Value pointed to by fixedPointer (initial): " << *fixedPointer << endl;
    *fixedPointer = 500;  // Modifying the value pointed to by the pointer
    cout << "Value pointed to by fixedPointer (after modification): " << *fixedPointer << endl;

    // Constant pointer to constant data
    const int* const immutableValue = new int(90); 
    cout << "Value pointed to by immutableValue: " << *immutableValue << endl;

    return 0;
}
