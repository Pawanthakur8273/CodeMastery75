#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void deleting(stack<int>& st, int pos) {
        if (pos <= 0) {
            st.pop();
            return;
        }
        int temp = st.top();
        st.pop();
        deleting(st, --pos);
        st.push(temp);
    }
    
    void deleteMid(stack<int>& s, int sizeOfStack) {
        deleting(s, sizeOfStack / 2);
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++) {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());

        while (!myStack.empty()) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}
