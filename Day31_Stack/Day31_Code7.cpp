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

// Function to print the elements of the stack
void stackPrinting(stack<int> st) {
    // Print each element until the stack is empty
    while(!st.empty()){
        cout << st.top() << " ";  // Print the top element
        st.pop();                  // Remove the top element
    }
}

int main() {
    stack<int> st;
    int data;

    // Input the data to be inserted into the sorted stack
    cin >> data;

    // Push elements 10, 20, ..., 50 onto the stack
    for(int i = 1; i <= 5; i++){
        st.push(i * 10);
    }

    // Print the stack before inserting the new element
    cout << "Printing before Inserting Element in a Sorted Stack: " << endl;
    stackPrinting(st);  
    cout << endl << endl;
    
    // Insert the data into the sorted stack
    insertSorted(st, data);

    // Print the stack after inserting the new element
    cout << "Printing After Inserting Element in a Sorted Stack" << endl;
    stackPrinting(st);

    return 0;
}
