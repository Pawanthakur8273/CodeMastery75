#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element into a sorted stack
void insertSorted(stack<int>& st, int data) {
    // If the stack is empty or the data is greater than the top element, push the data
    if(st.empty() || data > st.top()) {
        st.push(data);
        return;
    }
    
    // Temporarily hold the top element and pop it
    int temp = st.top();
    st.pop();
    
    // Recursively insert the data into the sorted stack
    insertSorted(st, data);
    
    // Push the temporarily held element back onto the stack
    st.push(temp);
}

// Function to sort the stack using recursion
void SortingStack(stack<int>& st) {
    // Base case: if the stack is empty, return
    if(st.empty()) {
        return;
    }
    
    // Temporarily hold the top element and pop it
    int temp = st.top();
    st.pop();
    
    // Recursively sort the remaining stack
    SortingStack(st);

    // Insert the temporarily held element into the sorted stack
    insertSorted(st, temp);
}

// Function to print the elements of the stack
void stackPrinting(stack<int> st) {
    // Print each element until the stack is empty
    while(!st.empty()) {
        cout << st.top() << " ";  // Print the top element
        st.pop();                  // Remove the top element
    }
}

int main() {
    stack<int> st;
    
    // Push elements onto the stack
    st.push(20);
    st.push(10);
    st.push(40);
    st.push(20);
    st.push(50);
    st.push(280);
    st.push(660);
    st.push(27);

    // Print the stack before sorting
    cout << "Printing before Sorting Stack: " << endl;
    stackPrinting(st);  
    cout << endl << endl;
    
    // Sort the stack
    SortingStack(st);

    // Print the stack after sorting
    cout << "Printing After Sorting Stack" << endl;
    stackPrinting(st);

    return 0;
}
