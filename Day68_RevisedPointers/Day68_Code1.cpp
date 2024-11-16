#include <iostream>
using namespace std;

// Function to demonstrate pointer basics
void pointerBasics() {
    int num = 10;
    int *ptr = &num;
    
    cout << "Pointer Basics:" << endl;
    cout << "Value of num: " << num << endl;
    cout << "Address of num (&num): " << &num << endl;
    cout << "Value of ptr (address stored in ptr): " << ptr << endl;
    cout << "Dereferencing ptr (*ptr): " << *ptr << endl;
    cout << "------------------------------" << endl;
}

// Function to demonstrate pointer arithmetic
void pointerArithmetic() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    cout << "Pointer Arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Value at ptr + " << i << ": " << *(ptr + i) << endl;
    }
    cout << "------------------------------" << endl;
}

// Function to demonstrate dynamic memory allocation
void dynamicMemory() {
    int *ptr = new int(25);
    cout << "Dynamic Memory Allocation:" << endl;
    cout << "Value allocated dynamically: " << *ptr << endl;
    
    delete ptr;  // Free the memory
    cout << "Memory deallocated successfully!" << endl;
    cout << "------------------------------" << endl;
}

// Function to demonstrate function pointers
void sampleFunction(int x) {
    cout << "Function Pointer Example: Value of x is " << x << endl;
}

void functionPointers() {
    void (*funcPtr)(int) = sampleFunction;
    cout << "Function Pointers:" << endl;
    funcPtr(100);  // Calling the function using function pointer
    cout << "------------------------------" << endl;
}

// Function to demonstrate double pointers
void doublePointers() {
    int num = 42;
    int *ptr = &num;
    int **dptr = &ptr;

    cout << "Double Pointers:" << endl;
    cout << "Value of num: " << num << endl;
    cout << "Value of *ptr: " << *ptr << endl;
    cout << "Value of **dptr: " << **dptr << endl;
    cout << "------------------------------" << endl;
}

// Main function
int main() {
    pointerBasics();
    pointerArithmetic();
    dynamicMemory();
    functionPointers();
    doublePointers();

    return 0;
}
