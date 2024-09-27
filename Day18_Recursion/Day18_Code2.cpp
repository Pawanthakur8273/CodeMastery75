#include <iostream>
using namespace std;
int binarySearch(int arr[], int s, int e, int target){
  int mid = s + (e-s)/2;
  if(s > e){
    return -1;
  }
  if(arr[mid] == target){
    return mid;
  }
  else if(arr[mid] < target){
    return binarySearch(arr, mid+1, e, target);
  }
  else{
    return binarySearch(arr, s, mid-1, target);
  }
}
int main() {
  int arr[] = {10,20,30,40,50,60,70,80,90,100};
  int size = sizeof(arr)/sizeof(arr[0]);
  int s = 0;
  int e = size-1;
  int target;
  cin >> target;
  cout << "The Target Found At index: "<<binarySearch(arr, s, e, target);
  return 0;
}
