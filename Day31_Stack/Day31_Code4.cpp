#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int>& st, int data) {
    // Base case: if the stack is empty, push the data onto the stack
    if(st.empty()) {
        st.push(data);
        return;
    }
    
    // Recursive case: remove the top element to reach the bottom
    int temp = st.top();
    st.pop();
    
    // Recursively call insertAtBottom to insert data at the bottom
    insertAtBottom(st, data);
    
    // Push the stored top element back onto the stack to maintain the original order
    st.push(temp);
}

int main() {
    int data1, data2, data3;
    
    // Input three data values
    cin >> data1 >> data2 >> data3;

    stack<int> st;

    // Pushing elements 10, 20, 30, 40 onto the stack
    for(int i = 1; i <= 4; i++) {
        st.push(i * 10);
    }

    // Inserting the input data at the bottom of the stack
    insertAtBottom(st, data1);
    insertAtBottom(st, data2);
    insertAtBottom(st, data3);

    // Displaying the elements of the stack after insertion
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
