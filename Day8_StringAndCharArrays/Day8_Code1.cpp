#include <iostream>
#include<string.h>
using namespace std;


int getLen(char ch[], int n){
  int i = 0;
  while(ch[i] != '\0'){
    i++;
  }
  return i;
}
void Reverse(char ch[], int n){
  int s = 0;
  int e = n-1;

  while(s<=e){
    swap(ch[s], ch[e]);
    s++;
    e--;
  }
}
void LowerToUpper(char ch[], int n){
    int idx = 0;
    while(ch[idx] != '\0'){
        if(ch[idx] >= 'a' && ch[idx] <='z'){
            ch[idx] = ch[idx] -'a'+'A';
        }
        idx++;
    }
}
bool CheckPalindrome(char ch[], int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(ch[s] != ch[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}
void RemoveAtTheRate(char ch[], int n){
    int idx = 0;
    while(ch[idx] != '\0'){
        if(ch[idx] == '@'){
            ch[idx] = ' ';
        }
        idx++;
    }
}

int main() {

  char ch[100];
  cin.getline(ch, 100);

  int len = getLen(ch, 100);
  cout << "Printing the len using GetLen Function " << len << endl;
  cout <<  "Printing the len using strLen Function "<<strlen(ch) << endl;

  cout << "Before Reversing: " << ch <<endl;
  Reverse(ch, len);
  cout << "After Reversing: " << ch << endl;

  LowerToUpper(ch, len);
  cout << "Converting LowerCase To UpperCase: " << ch << endl;
  
  cout << "Cheacking Palindrome: "<<  CheckPalindrome(ch, len) << endl;
  RemoveAtTheRate(ch, len);
  cout << "Removing At the Rate: " << ch << endl;
 


  return 0;
}
