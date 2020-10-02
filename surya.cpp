#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{
    //cin_tie(false)
    ios_base::sync_with_stdio(false); //Makes Input and output fas
    string a = "Geeks"; 
    string b = "function"; 
    cout << "Value of a before: " << a << endl; 
    cout << "Value of b before: " << b << endl; 
    swap(a,b); 
    cout << "Value of a now: " << a << endl; 
    cout << "Value of b now: " << b << endl; 
    return 0; 
}

