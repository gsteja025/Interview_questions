//Given a binary matrix of size NxN where 1 denotes that the number i can be converted to j, and 0 denotes it cannot be converted to. Also given are two numbers X(<N)and Y(<N), the task is to find the minimum number of steps required to convert the number X to Y. If there is no such way possible, print -1.//
// C++ implementation of the above approach 
#include <bits/stdc++.h> 
using namespace std; 
#define INF 99999 
#define size 10 
  
int findMinimumSteps(int mat[size][size], int x, int y, int n) 
{ 
    // dist[][] will be the output matrix that 
    // will finally have the shortest 
    // distances between every pair of numbers 
    int dist[n][n], i, j, k; 
  
    // Initially same as mat 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < n; j++) { 
            if (mat[i][j] == 0) 
                dist[i][j] = INF; 
            else
                dist[i][j] = 1; 
  
            if (i == j) 
                dist[i][j] = 1; 
        } 
    } 
  
    // Add all numbers one by one to the set 
    // of intermediate numbers. Before start of  
    // an iteration, we have shortest distances  
    // between all pairs of numbers such that the  
    // shortest distances consider only the numbers  
    // in set {0, 1, 2, .. k-1} as intermediate numbers. 
    // After the end of an iteration, vertex no. k is  
    // added to the set of intermediate numbers and  
    // the set becomes {0, 1, 2, .. k} 
    for (k = 0; k < n; k++) { 
  
        // Pick all numbers as source one by one 
        for (i = 0; i < n; i++) { 
  
            // Pick all numbers as destination for the 
            // above picked source 
            for (j = 0; j < n; j++) { 
  
                // If number k is on the shortest path from 
                // i to j, then update the value of dist[i][j] 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    } 
  
    // If no path 
    if (dist[x][y] < INF) 
        return dist[x][y]; 
    else
        return -1; 
} 
  
// Driver Code 
int main() 
{ 
  
    int mat[size][size] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 
                            { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, 
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                            { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } }; 
  
    int x = 2, y = 3; 
  
    cout << findMinimumSteps(mat, x, y, size); 
} 
