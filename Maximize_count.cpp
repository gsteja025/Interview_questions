//Given an array arr[] and an integer K, the task is to print the maximum number of non-overlapping subarrays with a sum equal to K.
// C++ Program to implement 
// the above approach 
  
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to count the maximum 
// number of subarrays with sum K 
int CtSubarr(int arr[], int N, int K) 
{ 
  
    // Stores all the distinct 
    // prefixSums obtained 
    unordered_set<int> st; 
  
    // Stores the prefix sum 
    // of the current subarray 
    int prefixSum = 0; 
  
    st.insert(prefixSum); 
  
    // Stores the count of 
    // subarrays with sum K 
    int res = 0; 
  
    for (int i = 0; i < N; i++) { 
        prefixSum += arr[i]; 
  
        // If a subarray with sum K 
        // is already found 
        if (st.count(prefixSum - K)) { 
  
            // Increase count 
            res += 1; 
  
            // Reset prefix sum 
            prefixSum = 0; 
  
            // Clear the set 
            st.clear(); 
            st.insert(0); 
        } 
  
        // Insert the prefix sum 
        st.insert(prefixSum); 
    } 
    return res; 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { -2, 6, 6, 3, 5, 4, 1, 2, 8 }; 
    int N = sizeof(arr) / sizeof(arr[0]); 
    int K = 10; 
    cout << CtSubarr(arr, N, K); 
}
