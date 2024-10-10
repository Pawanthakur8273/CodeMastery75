#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& st, int data) {
    // If the stack is empty, push the data
    if(st.empty()) {
        st.push(data);
        return;
    }
    
    // Temporarily hold the top element and pop it
    int temp = st.top();
    st.pop();
    
    // Recursively insert data at the bottom
    insertAtBottom(st, data);
    
    // Push the temporarily held element back onto the stack
    st.push(temp);
}

// Function to reverse the stack using recursion
void reverseAStack(stack<int>& st){
    // Base case: if the stack is empty, do nothing
    if(st.empty()){
        return;
    }

    // Temporarily hold the top element and pop it
    int temp = st.top();
    st.pop();

    // Recursively reverse the remaining stack
    reverseAStack(st);

    // Insert the temporarily held element at the bottom of the stack
    insertAtBottom(st, temp);
}

// Function to print the elements of the stack
void stackPrinting(stack<int> st){
    // Print each element until the stack is empty
    while(!st.empty()){
        cout << st.top() << " ";  // Print the top element
        st.pop();                  // Remove the top element
    }
}

int main() {
    stack<int> st;

    // Push elements 10, 20, ..., 100 onto the stack
    for(int i = 1; i <= 10; i++){
        st.push(i * 10);
    }

    // Print the stack before reversing
    cout << "Printing Stack before Reversing: " << endl;
    stackPrinting(st);  
    cout << endl << endl;

    // Reverse the stack
    reverseAStack(st);

    // Print the stack after reversing
    cout << "Printing Stack After Reversing: " << endl;
    stackPrinting(st);

    return 0;
}
