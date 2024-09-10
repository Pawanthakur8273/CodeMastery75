## Extended Description

This C++ program demonstrates various basic operations on arrays. It includes functions for inserting and deleting elements, finding the largest and smallest elements, reversing the array, and removing duplicate elements. Each function is designed to perform a specific task and is tested within the `main` function.

### Functions Overview

1. **`bool isSorted(int arr[], int size)`**:
   - **Description**: Checks if the array is sorted in non-decreasing order.
   - **Parameters**: 
     - `arr[]`: The array to be checked.
     - `size`: The number of elements in the array.
   - **Returns**: `true` if the array is sorted, otherwise `false`.

2. **`int insertInArray(int arr[], int size, int ele, int pos)`**:
   - **Description**: Inserts an element into the array at a specified position.
   - **Parameters**:
     - `arr[]`: The array where the element will be inserted.
     - `size`: The current number of elements in the array.
     - `ele`: The element to be inserted.
     - `pos`: The position where the element should be inserted.
   - **Returns**: The new size of the array after insertion.

3. **`int DeletionInArray(int arr[], int size, int ele)`**:
   - **Description**: Deletes the first occurrence of a specified element from the array.
   - **Parameters**:
     - `arr[]`: The array from which the element will be deleted.
     - `size`: The current number of elements in the array.
     - `ele`: The element to be deleted.
   - **Returns**: The new size of the array after deletion. If the element is not found, it prints an error message and returns the original size.

4. **`int findLargestEle(int* arr, int size)`**:
   - **Description**: Finds the largest element in the array.
   - **Parameters**:
     - `arr`: The array to search.
     - `size`: The number of elements in the array.
   - **Returns**: The largest element.

5. **`int findSmallestEle(int* arr, int size)`**:
   - **Description**: Finds the smallest element in the array.
   - **Parameters**:
     - `arr`: The array to search.
     - `size`: The number of elements in the array.
   - **Returns**: The smallest element.

6. **`int secondLargestEle(int *arr, int size)`**:
   - **Description**: Finds the second largest element in the array.
   - **Parameters**:
     - `arr`: The array to search.
     - `size`: The number of elements in the array.
   - **Returns**: The second largest element.

7. **`int secondSmallestEle(int *arr, int size)`**:
   - **Description**: Finds the second smallest element in the array.
   - **Parameters**:
     - `arr`: The array to search.
     - `size`: The number of elements in the array.
   - **Returns**: The second smallest element.

8. **`void ReverseAnArray(int arr[], int size)`**:
   - **Description**: Reverses the elements of the array.
   - **Parameters**:
     - `arr[]`: The array to be reversed.
     - `size`: The number of elements in the array.

9. **`int RemoveDuplicates(int arr[], int size)`**:
   - **Description**: Removes duplicate elements from the array and returns the new size of the array.
   - **Parameters**:
     - `arr[]`: The array from which duplicates will be removed.
     - `size`: The number of elements in the array.
   - **Returns**: The new size of the array after removing duplicates.

10. **`int RemoveDuplicatesEff(int arr[], int size)`**:
    - **Description**: Efficiently removes duplicate elements from the array and returns the new size of the array.
    - **Parameters**:
      - `arr[]`: The array from which duplicates will be removed.
      - `size`: The number of elements in the array.
    - **Returns**: The new size of the array after removing duplicates.

11. **`void printArray(int arr[], int n)`**:
    - **Description**: Prints the elements of the array.
    - **Parameters**:
      - `arr[]`: The array to be printed.
      - `n`: The number of elements in the array.

### Main Function

The `main` function demonstrates the use of the above functions with a sample array. It performs the following operations:
- Prints the original array.
- Inserts elements into the array and prints the updated array.
- Deletes an element from the array and prints the updated array.
- Finds and prints the largest, smallest, second largest, and second smallest elements.
- Reverses the array and prints the result.
- Checks if the array is sorted and prints the result.
- Removes duplicates from the array using two different approaches and prints the results.

The code illustrates basic array manipulations and serves as a foundational exercise in understanding array operations in C++.
