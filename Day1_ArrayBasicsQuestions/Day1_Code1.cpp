#include<iostream>
#include<limits.h>
using namespace std;

bool isSorted(int arr[], int size){

  for(int i = 1;  i < size; i++){
    if(arr[i-1] > arr[i]){
      return false;
    }
  }
  return true;

}

int insertInArray(int arr[], int size, int ele, int pos){
  for(int i = size; i > pos; i--){
    arr[i] = arr[i-1];
  }
  arr[pos] = ele;
  return size+1;
}

int DeletionInArray(int arr[], int size, int ele){
  int idx = -1;

  for(int i = 0; i < size; i++){
    if(arr[i] == ele){
      idx = i;
    }
  }

  if(idx == -1){
    cout <<"No Such Element found" << endl;
    return size;
  }
  else{
    for(int i = idx; i < size; i++){
      arr[i] = arr[i+1];
    }
  }
  return size-1;
}

int findLargestEle(int* arr, int size){
  int Largest = INT_MIN;

  for(int i = 0; i < size; i++){
    if(arr[i] > Largest){
      Largest = arr[i];
    }
  }
  return Largest;
}

int findSmallestEle(int* arr, int size){
  int Smallest = INT_MAX;

  for(int i = 0; i < size; i++){
    if(arr[i] < Smallest){
      Smallest = arr[i];
    }
  }
  return Smallest;
}

int secondLargestEle(int *arr, int size){
  int Largest = findLargestEle(arr, size);
  int SecondLargest = INT_MIN;

  for(int i = 0; i < size; i++){
    if(arr[i] != Largest){
      if(arr[i] > SecondLargest){
        SecondLargest = arr[i];
      }
    }
  }
    return SecondLargest;
}

int secondSmallestEle(int *arr, int size){
  int Smallest = findSmallestEle(arr, size);
  int SecondSmallest = INT_MAX;

  for(int i = 0; i < size; i++){
    if(arr[i] != Smallest){
      if(arr[i] < SecondSmallest){
        SecondSmallest = arr[i];
      }
    }
  }
    return SecondSmallest;
}

void ReverseAnArray(int arr[], int size){
  int s = 0;
  int e = size-1;
  while(s<=e){
    int temp = arr[e];
    arr[e] = arr[s];
    arr[s] = temp;
    s++;
    e--;
  }
}

int RemoveDuplicates(int arr[], int size){
  int* temp = new int[size];
  temp[0] = arr[0];
  int idx = 1;
  for(int i = 1; i < size; i++){
    if(temp[idx-1] != arr[i]){
      temp[idx] = arr[i];
      idx++;
    }
  }

  for(int i = 0; i < idx; i++){
    arr[i] = temp[i];
  }
  return idx;
}

int RemoveDuplicatesEff(int arr[], int size){
  int idx = 1;
  for(int i = 1; i < size; i++){
    if(arr[idx-1] != arr[i]){
      arr[idx] = arr[i];
      idx++;
    }
  }
  return idx;
}

void printArray(int arr[], int n){
  cout << "Printing Array: " << endl;
  for(int i = 0; i < n; i++){
    cout << arr[i] <<" ";
  }
  cout << endl << endl;
}

int main(){

  //Basic Questions on array

  int arr[] = {10,20,30,40,50,60};
  int size = sizeof(arr)/sizeof(arr[0]);

  //Printing Normal Array
  printArray(arr, size);

  //Insert in an Array
  cout <<"After Insertion of 100 ";
  size = insertInArray(arr, size, 100, size);
  size = insertInArray(arr, size, 100, size);
  size = insertInArray(arr, size, 100, size);
  printArray(arr, size);

  //Deletion in an Array
  cout << "After Deletion of 10 ";
  size = DeletionInArray(arr, size, 10);
  printArray(arr, size);
  

  //checking Largest Element
  cout << "Largest element is: " << endl;
  cout << findLargestEle(arr, size) << endl << endl;

  //checking Smallest Element
  cout << "Smallest element is: " << endl;
  cout << findSmallestEle(arr, size) << endl << endl;
  
  //checking Second Largest Element
  cout << "Second Largest element is: " << endl;
  cout << secondLargestEle(arr, size) << endl << endl;

  //checking Second Smallest Element
  cout << "Second Smallest element is: " << endl;
  cout << secondSmallestEle(arr, size) << endl << endl;

  //reverse An Array
  cout <<"Reversing and then  ";
  ReverseAnArray(arr, size);
  printArray(arr, size);

  //Cheacking an element is present or Not
  cout << "Is Array Sorted?" << endl;
  int ans = isSorted(arr, size);
  if(ans){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }

  cout << endl;
  // Removing Duplicate Elements form the Array
  size = RemoveDuplicates(arr, size);
  cout << "Removed Duplicates and then ";
  printArray(arr, size);

  // Removing Duplicate Elements Efficient Approach form the Array
  size = RemoveDuplicatesEff(arr, size);
  cout << "Removed Duplicates using Efficient Approach and then ";
  printArray(arr, size);
  

  return 0;
}
