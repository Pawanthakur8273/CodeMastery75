#include <iostream>
#include <stack>

using namespace std;

void insertAtpos(stack<int>& st, int pos, int data) {
    // Base case: insert the data when the position reaches 0 or the stack is empty
    if (pos <= 0 || st.empty()) {
        st.push(data);
        return;
    }

    // Store the top element and pop it to go deeper in the stack
    int temp = st.top();
    st.pop();
    
    // Recursive call with decremented position
    insertAtpos(st, --pos, data);

    // Push the popped element back to maintain the original order
    st.push(temp);
}

int main() {
    int pos;
    cout << "Enter the position to insert the data (0-based index): ";
    cin >> pos;

    int data;
    cout << "Enter the data to insert: ";
    cin >> data;

    stack<int> st;

    // Sample initial stack (can be modified as per the requirement)
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // Inserting data at the specified position
    insertAtpos(st, pos, data);

    // Display the stack after insertion
    cout << "Stack after insertion: " << endl;
    int i = 0;
    while (!st.empty()) {
        cout << i++ << ": " << st.top() << endl;
        st.pop();
    }

    return 0;
}
