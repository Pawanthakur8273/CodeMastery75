#include <iostream>
using namespace std;
//print
void print(int n){
  if(n == 0){
    return;
  }
  print(n-1);
  cout << n << " ";
}
//sum
int sum(int n){
  if(n == 0){
    return n;
  }
  int ans = n + sum(n-1);
  return ans;
}
//pow 2^n
int pow(int n){
  if(n == 0){
    return 1;
  }
  int ans = 2 * pow(n-1);
  return ans;
}
// fib
int fib(int n){
  if(n == 0){
    return 0;
  }
  if(n == 1){
    return 1;
  }
  int ans = fib(n-1) + fib(n-2);
  return ans;
}
// factorial
int factorial(int n){
  if(n == 0 || n == 1){
    return 1;
  }
  int ans = n * factorial(n-1);
  return ans;
}
int main() {
  int n;
  cin >> n;
  cout << "Printing the numbers from 1 to n: "<< endl;
  print(n);
  cout <<endl << "Sum of N Number is: "<<sum(n) << endl;
  cout << "Nth power of 2 is: " << pow(n) << endl;
  cout << "Nth fibbonaci number is: " <<fib(n) << endl;
  cout << "Nth factorial is: "<< factorial(n) << endl;
  return 0;
}
