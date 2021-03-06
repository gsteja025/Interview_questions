//Given a string S, the task is to remove all the duplicates in the given string.
// CPP program to remove duplicate character 
// from character array and print in sorted 
// order 
#include <bits/stdc++.h> 
using namespace std; 
  
char *removeDuplicate(char str[], int n) 
{ 
   // Used as index in the modified string 
   int index = 0;    
     
   // Traverse through all characters 
   for (int i=0; i<n; i++) { 
         
     // Check if str[i] is present before it   
     int j;   
     for (j=0; j<i; j++)  
        if (str[i] == str[j]) 
           break; 
       
     // If not present, then add it to 
     // result. 
     if (j == i) 
        str[index++] = str[i]; 
   } 
     
   return str; 
} 
  
// Driver code 
int main() 
{ 
  ios_base::sync_with_stdio(0);
   char str[]= "geeksforgeeks"; 
   int n = sizeof(str) / sizeof(str[0]); 
   cout << removeDuplicate(str, n); 
   return 0; 
} 
/*Another method of solving this is using map i,e key and value pairs.
Count the number of times each character repeated.Then,remove all the characters with map value >1. So now we can remove all the duplicates.
