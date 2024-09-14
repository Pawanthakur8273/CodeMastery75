#include <iostream>
using namespace std;

int binarySeach(int arr[], int n, int target){
  int s = 0;
  int e = n-1;
  int mid = s + (e-s)/2;

  while(s <= e){
    if(arr[mid] == target){
      return mid;
    }
    else if(target > arr[mid]){
      s = mid +1;
    }
    else{
      e = mid -1;
    }
    mid = s + (e-s)/2;
  }
}

int main() {

  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "Index of Targeted element is: " << endl;
  cout << binarySeach(arr, n, 10);
 
  return 0;
}
