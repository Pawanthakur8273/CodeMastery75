## Extended Description

This C++ program demonstrates several array manipulation techniques. It includes functions for moving zeros to the end of an array, rotating an array to the left, and performing rotation using the reversal algorithm.

### Functions Overview

1. **`void moveZerosToEnd(int arr[], int size)`**:
   - **Description**: Moves all zero elements in the array to the end, preserving the order of non-zero elements.
   - **Parameters**:
     - `arr[]`: The array to be modified.
     - `size`: The number of elements in the array.

2. **`void LeftRotateArray(int arr[], int size)`**:
   - **Description**: Performs a left rotation of the array by one position.
   - **Parameters**:
     - `arr[]`: The array to be rotated.
     - `size`: The number of elements in the array.

3. **`void reverse(int arr[], int s, int e)`**:
   - **Description**: Reverses a subarray from index `s` to index `e`.
   - **Parameters**:
     - `arr[]`: The array to be reversed.
     - `s`: Start index of the subarray.
     - `e`: End index of the subarray.

4. **`void LeftRotateByReversalAlgo(int arr[], int size, int k)`**:
   - **Description**: Rotates the array to the left by `k` positions using the reversal algorithm.
   - **Parameters**:
     - `arr[]`: The array to be rotated.
     - `size`: The number of elements in the array.
     - `k`: Number of positions to rotate the array.

5. **`void printArray(int arr[], int n)`**:
   - **Description**: Prints the elements of the array.
   - **Parameters**:
     - `arr[]`: The array to be printed.
     - `n`: The number of elements in the array.

### Main Function

The `main` function demonstrates the use of these functions with a sample array. It performs the following operations:
- Prints the original array.
- Moves zeros to the end and prints the updated array.
- Rotates the array left by one position and prints the result.
- Rotates the array left by a specified number of positions using the reversal algorithm and prints the result.

This code illustrates basic array operations and provides a practical example of how to handle array manipulations in C++.
