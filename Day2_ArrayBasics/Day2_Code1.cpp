#include <iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
using namespace std;

//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
int Unique(int arr[], int n){
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans = ans^arr[i];
  }
  return ans;
}

// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
int Missing(int arr[], int n){
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum = sum + arr[i];
  }
  int totalSum = (n*n + n)/2;
  int ans = totalSum - sum;
}
//Given an array of integers nums and an integer target, return true if the two numbers such that they add up to target.
bool isPresent(int nums[], int n, int target){
        int i = 0;
        int j = n-1;
        while(i < j){
            if(nums[i] + nums[j] == target){
                return true;
                break;
            }
            else if(nums[i] + nums[j] > target){
                j--;
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }
        }
        return false;
    }

//Leaders in an array:  An element is a Leader if it is greater than all the elements to its right side.
void FindLeader(int arr[], int n){
  int currLeader = arr[n-1];
  cout << currLeader <<" ";
  for(int i = n-2; i >=  0; i--){
    if(arr[i] > currLeader){
      currLeader = arr[i];
      cout << currLeader <<" ";
    }
  }
}

//find out the maximum difference between any two elements such that larger element appears after the smaller number. 
int MaxDiff(int arr[], int n){
  int maxi = INT_MIN;

  for(int i = 0; i < n-2;  i++){
    for(int j = i+1; j < n-1;  j++){
      if(arr[i] < arr[j]){
        int diff = arr[j] - arr[i];
        if(diff > maxi){
          maxi =  diff;
        }
      }
    }
  }
  return maxi;

}

//Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

int main() {
  int arr[] = {2,7,11,15};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "Maximum difference: "<< endl;
  int diff = MaxDiff(arr, n);
  cout << diff << endl << endl;
  cout << "Leaders in an array: " << endl;
  FindLeader(arr, n);
  cout << endl << endl;
  cout << "Two Sum present: " << endl;
  cout << isPresent(arr, n, 8);
  
  return 0;
}
