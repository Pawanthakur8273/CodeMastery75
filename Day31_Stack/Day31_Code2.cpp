#include <iostream>
#include <stack>
using namespace std;

// Recursive function to get the middle element of the stack
int getmidElement(stack<int> st, int pos) {
  // Base case: if position is 0, return the top element (middle element)
  if(pos <= 0) {
    return st.top();
  }
  
  // Decrement position and store the top element
  pos--;
  int temp = st.top();
  st.pop();  // Remove top element to move towards the middle

  // Recursive call to get the middle element
  int ans = getmidElement(st, pos);
  
  // Push the element back to restore the stack after recursion
  st.push(temp);
  
  return ans; // Return the middle element
}

int main() {
  stack<int> st;
  
  // Pushing elements 10, 20, 30, 40 onto the stack
  for(int i = 1; i <= 4; i++) {
    st.push(i * 10);
  }
  
  // Printing the middle element of the stack
  cout << getmidElement(st, st.size() / 2);
  
  return 0;
}
