#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  
  string str = "jannnnn";
  stack<char> st;

  for(int i = 0; i < str.length(); i++){
    char ch = str[i];
    st.push(ch);
  }
  cout << "Reversed the string: " << endl;
  while(!st.empty()){
    cout << st.top();
    st.pop();
  }
  return 0;
}
