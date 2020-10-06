//A subarray is called alternating if any two consecutive numbers in it have opposite signs (i.e. one of them should be negative, whereas the other should be positive).

//Given an array of n integers. For each index i, we need to find the length if the longest alternating subarray starting at i.

// CPP program to find longest alternating 
// subarray starting from every index. 
#include <bits/stdc++.h> 
using namespace std; 
  
void longestAlternating(int arr[], int n) 
{ 
    int count[n]; 
  
    // Fill count[] from end.  
    count[n - 1] = 1; 
    for (int i = n - 2; i >= 0; i--) { 
        if (arr[i] * arr[i + 1] < 0) 
            count[i] = count[i + 1] + 1; 
        else
            count[i] = 1; 
    } 
  
    // Print result 
    for (int i = 0; i < n; i++) 
        cout << count[i] << " "; 
} 
  
// Driver code 
int main() 
{ 
  
    ios_base::sync_with_stdio(false);
    int a[] = { -5, -1, -1, 2, -2, -3 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    longestAlternating(a, n); 
    return 0; 
} 
