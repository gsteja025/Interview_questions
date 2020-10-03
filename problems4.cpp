//Given an array arr[] of size n having both positive and negative integer excluding zero. The task is to find the subsequence with an alternating sign having maximum size and maximum sum that is, in a subsequence sign of each adjacent element is opposite for example if the first one is positive then the second one has to be negative followed by another positive integer and so on.
// C++ implementation to find the 
// subsequence with alternating sign 
// having maximum size and maximum sum. 
  
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find the subsequence 
// with alternating sign having 
// maximum size and maximum sum. 
void findSubsequence(int arr[], int n) 
{ 
    int sign[n] = { 0 }; 
  
    // Find whether each element 
    // is positive or negative 
    for (int i = 0; i < n; i++) { 
        if (arr[i] > 0) 
            sign[i] = 1; 
        else
            sign[i] = -1; 
    } 
  
    int k = 0; 
    int result[n] = { 0 }; 
  
    // Find the required subsequence 
    for (int i = 0; i < n; i++) { 
  
        int cur = arr[i]; 
        int j = i; 
  
        while (j < n && sign[i] == sign[j]) { 
  
            // Find the maximum element 
            // in the specified range 
            cur = max(cur, arr[j]); 
            ++j; 
        } 
  
        result[k++] = cur; 
  
        i = j - 1; 
    } 
  
    // print the result 
    for (int i = 0; i < k; i++) 
        cout << result[i] << " "; 
    cout << "\n"; 
} 
  
// Driver code 
int main() 
{ 
    // array declaration 
    int arr[] = { -4, 9, 4, 11, -5, -17, 9, -3, -5, 2 }; 
  
    // size of array 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    findSubsequence(arr, n); 
  
    return 0; 
} 
