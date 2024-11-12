#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
  int start = 0;
  int end = n-1;
  //there is some flaw in below line, HW ?
  int mid = (start+end)/2;
  while(start <= end) {
    ///found
    if(arr[mid] == target) {
      //return index of the found element
      return mid;
    }
    else if(target > arr[mid]) {
      //right me jao
      start = mid + 1;
    }
    else if(target < arr[mid]) {
      //left me jao 
      end = mid - 1;
    }
    //mid update
    mid = (start + end)/2;
  }
  //agar yaha tk pohohche ho
  //iska matlab element nahi mila tumhe
  return -1;
}

int findFirstOccurence(int arr[], int n, int target) {
  int s = 0;
  int e = n-1;
  int mid = (s+e)/2;

  //BEST Practice
  //int mid = s +(e-s)/2;
  
  int ans = -1;

  while(s<=e) {
    if(arr[mid]==target) {
      //ans store
      ans = mid;
      //left me jao
      e = mid-1;
    }
    else if(target > arr[mid]) {
      //right me jao
      s = mid+1;
    }
    else if(target < arr[mid]) {
      //left me jao
      e = mid-1;
    }
    //galti yaha krte h hmesha
    mid = (s+e)/2;
  }
  return ans;
}


int findLastOccurence(int arr[], int n, int target) {
  int s = 0;
  int e = n-1;
  int mid = s +(e-s)/2;
  int ans = -1;

  while(s<=e) {
    if(arr[mid]==target) {
      //ans store
      ans = mid;
      //right me jao
      s = mid+1;
    }
    else if(target > arr[mid]) {
      //right me jao
      s = mid+1;
    }
    else if(target < arr[mid]) {
      //left me jao
      e = mid-1;
    }
    //galti yaha krte h hmesha
    mid = (s+e)/2;
  }
  return ans;
}

int findTotalOccurence(int arr[], int n, int target) {
  int firstOcc = findFirstOccurence(arr, n, target);
  int lastOcc = findLastOccurence(arr, n, target);
  int total = lastOcc - firstOcc +1 ;
  return total;
}

int findMissingElement(int arr[], int n) {
  int s = 0;
  int e = n-1;
  int mid = s + (e-s)/2;
  int ans = -1;

  while(s <= e) {
    int diff = arr[mid] - mid;

    if(diff == 1) {
      //right me jao
      s = mid+1;
    }
    else {
      //ans store
      ans = mid;
      //left me jao
      e = mid - 1;
    }
     mid = s + (e-s)/2;
  }


  //HW -> How can we remove this, by modifying the above logic
  if(ans +1 == 0)
    return n+1;
  
  return ans+1;
}


int main() {

  int arr[] = {1,2,3,4,5,6,7,8};
  //int target = 30;
  int n =8;

  cout<<"Missing element is: " << findMissingElement(arr, n);

  // int ans = findTotalOccurence(arr, n, target);
  // cout << "Ttoal Occ is:  "<< ans << endl;
  // int ansIndex = findLastOccurence(arr, n, target);

  // if(ansIndex == -1) {
  //  cout << "Element not found " << endl;
  // }
  // else {
  //  cout << "Element found at Index: " << ansIndex << endl;
  // }
  

  return 0;
}



//Peak Element in Mountain Array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
       

        while(s < e) {
            int mid = s + (e-s)/2;
            if(arr[mid] < arr[mid+1] ){
                //A wali line me hu
                //peak right me exist krti h 
                s = mid + 1;
            }
            else {
                //yaa toh main B line pr hu
                //ya toh main Peak element pr hu
                e = mid;
            }
            //mid update
            
        }
        return e;
    }
};

//find pivot index:

#include <iostream>
#include<vector>
using namespace std;

int findPivotIndex(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s <= e) {
            //corner case
            if(s == e) {
                //single element
                return s;
            }

            if(arr[mid] > arr[mid+1])
                return mid;
            else if(arr[mid] < arr[mid-1])
                return mid-1;
            else if(arr[s] > arr[mid] ) 
                e = mid - 1;
            else 
                s = mid + 1;
            
            mid = s + (e-s)/2;
        }
        return -1;

    }


int main() {
  vector<int> v;


  v.push_back(2);
  v.push_back(4);
  v.push_back(6);
  v.push_back(8);
  v.push_back(10);

  int pivotIndex = findPivotIndex(v);
  cout << "Pivot Index is: " << pivotIndex << endl;
  return 0;
}


//search in a rotated and sorted array 
class Solution {
public:

    int findPivotIndex(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s <= e) {
            //corner case
            if(s == e) {
                //single element
                return s;
            }

            if(mid+1 < n && arr[mid] > arr[mid+1])
                return mid;
            else if(mid-1 >=0 && arr[mid] < arr[mid-1])
                return mid-1;
            else if(arr[s] > arr[mid] ) 
                e = mid - 1;
            else 
                s = mid + 1;
            
            mid = s + (e-s)/2;
        }
        return -1;

    }

    int binarySearch(vector<int>& arr, int s, int e, int target) {
        int mid = s + (e-s)/2;
        while(s<=e) {
            if(arr[mid] == target) {
                return mid;
            }
            if(target > arr[mid]) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = findPivotIndex(nums);
        cout << "Pivot Index us: " << pivotIndex << endl;
        int n = nums.size();
        int ans = -1;

        //search in A
        if(target >= nums[0] && target <= nums[pivotIndex]) {
            ans = binarySearch(nums, 0, pivotIndex, target);
        }
        else {
            ans = binarySearch(nums, pivotIndex+1, n-1, target);
        }
        return ans;
    }
};


//find square root of a number 
class Solution {
public:


    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long int mid = s + (e-s)/2;
        int ans = -1;

        while(s <= e) {
            //kya mid hi toh answer nahi
            if(mid*mid == x) {
                return mid;
            }
            else if(mid*mid < x) {
                //ans store
                //right me jao
                ans = mid;
                s = mid+1;
            }
            else {
                //left me jana h 
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};


//binary search in a  2D matrix 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row*col;

        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s <= e) {
            int rowIndex = mid/col;
            int colIndex = mid % col;
            int currNumber = matrix[rowIndex][colIndex];

            if(currNumber == target)
                return true;
            else if(target > currNumber ) {
                //right;
                s = mid + 1;
            } 
            else {
                //left;
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return false;
    }
};

#include <iostream>
using namespace std;

int getQuotient(int divisor, int dividend) {
  int s = 0;
  int e = dividend;
  int ans = -1;
  int mid = s + (e-s)/2;

  while(s <= e) {
    
    if(mid * divisor == dividend) {
      return mid;
    }
    if(mid * divisor < dividend) {
      //ans store
      ans = mid;
      //right me jao
      s = mid+1;
    }
    else {
      //left
      e = mid - 1;
    }
    mid = s + (e-s)/2;
  }
  return ans;
}
 
int searchNearlySorted(int arr[], int n, int target) {
  int s = 0;
  int e = n-1;
  int mid = s + (e-s)/2;

  while(s <= e) {
    if(mid-1 >= 0 &&  arr[mid-1] == target) {
      return mid-1;
    }
    if(arr[mid] == target)
      return mid;
    
    if(mid+1 < n && arr[mid+1] == target)
      return mid+1;

    if(target > arr[mid] ){
      //right
      s = mid + 2;
    }
    else {
      //left
      e = mid - 2;
    }
    mid = s + (e-s)/2;
  }
  return -1;
}

int findOddOccuringElement(int arr[], int n) {
  int s = 0;
  int e = n-1;
  int mid = s + (e-s)/2;

  while(s <= e) {

    //single element
    if(s == e) {
      return s;
    }

    //mid check -> even or odd
    if(mid & 1) { //mid&1 -> true -> odd number
      if(mid-1 >=0 && arr[mid-1] == arr[mid]) {
        //right me jao
        s = mid + 1;
      }
      else {
        //left me jao
        e = mid - 1;
      }
    }
    else {
      //even
      if(mid+1 < n && arr[mid] == arr[mid+1]){
        //right me jao
        s = mid + 2;
      }
      else {
        //ya toh main right part pr khada hu
        //ya toh main answer k upar khada hu
        //that's why e = mid krra hu
        // kyoki e = mid - 1; se ans lost ho skta h 
        e = mid;    
      }
    }
    mid = s + (e-s)/2;
  }
  return -1;
}












int main() {

  // int divisor = 7;
  // int dividend = 29;
  
  // int ans = getQuotient(abs(divisor), abs(dividend));

  // //now we need to decide k sign konsa lagaye +ve ya negative

  // if((divisor >0 && dividend <0) || (divisor <0 && dividend > 0)) {
  //  ans = 0 - ans;
  // }

  // cout << "Final Ans is: " << ans << endl;

  // int arr[] = {20,10,30,50,40,70,60};
  // int n = 7;
  // int target = 20;

  // int targetIndex = searchNearlySorted(arr, n, target);

  // if(targetIndex == -1) {
  //  cout << "Element Not found" << endl;
  // }
  // else {
  //  cout << "Element Found at Index: " << targetIndex << endl;
  // }


  int arr[] = {10,10,10};
  int n = 13;

  int ansIndex = findOddOccuringElement(arr, n);

  cout << "Final Ans is: "<< arr[ansIndex] << endl; 

  








  
  return 0;
}
