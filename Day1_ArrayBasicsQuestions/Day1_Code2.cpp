#include <iostream>
using namespace std;

void moveZerosToEnd(int arr[], int size){
  int j = 0;
  for(int i = 0; i < size; i++){
    if(arr[i] != 0){
      swap(arr[i], arr[j]);
      j++;
    }
  }
}
void LeftRotateArray(int arr[], int size){
  int temp = arr[size-1];
  for(int i = size-1; i>0; i--){
    arr[i] = arr[i-1];
  }
  arr[0] = temp;
}
void reverse(int arr[],int s, int e){
  while(s < e){
    swap(arr[s], arr[e]);
    s++;
    e--;
  }
}
void LeftRotateByReversalAlgo(int arr[], int size, int k){
  reverse(arr, 0, k-1);
  reverse(arr, k, size-1);
  reverse(arr, 0, size-1);
}
void printArray(int arr[], int n){
  for(int i = 0; i < n; i++){
    cout << arr[i] <<" ";
  }
  cout << endl << endl;
}

int main() {
  int arr[] = {1,2,3,4,5,6};
  int size = sizeof(arr)/sizeof(arr[0]);

  cout <<"Printing Before Moving: " << endl;
  printArray(arr, size);
  cout << "Printing After Moving: " << endl;
  moveZerosToEnd(arr, size);
  printArray(arr, size);

  cout << "Left Rotating a Array by 1: " << endl;
  LeftRotateArray(arr, size);
  printArray(arr, size);

  cout << "Left Rotate an Array by k times: " << endl;
  LeftRotateByReversalAlgo(arr, size, 2+1);
  printArray(arr, size);
  return 0;
}
