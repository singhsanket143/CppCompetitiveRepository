#include <iostream> 
#include <limits.h>
using namespace std;
int sum(int freq[], int i, int j) 
{ 
    int s = 0; 
    for (int k = i; k <=j; k++) 
       s += freq[k]; 
    return s; 
} 
int optCost(int freq[], int i, int j) 
{ 
   if (j < i)      
     return 0; 
   if (j == i)     
     return freq[i]; 
   int fsum = sum(freq, i, j); 
   int min = INT_MAX; 
   for (int r = i; r <= j; ++r) 
   { 
       int cost = optCost(freq, i, r-1) +  
                  optCost(freq, r+1, j); 
       if (cost < min) 
          min = cost; 
   } 
   return min + fsum; 
} 
int optimalSearchTree(int keys[], int freq[], int n) 
{ 
     return optCost(freq, 0, n-1); 
} 

int main() 
{ 
    int keys[] = {10, 12, 20}; 
    int freq[] = {34, 8, 50}; 
    int n = sizeof(keys)/sizeof(keys[0]); 
    cout<<optimalSearchTree(keys, freq, n);
    return 0; 
} 