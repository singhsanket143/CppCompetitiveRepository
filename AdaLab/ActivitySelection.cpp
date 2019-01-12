/*
By Sanket Singh
*/
#include <bits/stdc++.h> 
using namespace std; 
class Activitiy 
{ 
public:
    int start, finish; 
}; 
  
bool activityCompare(Activitiy s1, Activitiy s2) 
{ 
    return (s1.finish < s2.finish); 
} 
  
void printMaxActivities(Activitiy arr[], int n) 
{ 
    sort(arr, arr+n, activityCompare); 
    // cout << "Following activities are selected n"; 
    int i = 0; 
    // cout << "(" << arr[i].start << ", " << arr[i].finish << "), "; 
    cout<<i<<" ";
    for (int j = 1; j < n; j++) 
    { 
      if (arr[j].start >= arr[i].finish) 
      { 
          // cout << "(" << arr[j].start << ", "
          //     << arr[j].finish << "), "; 
        cout<<j<<" ";
          i = j; 
      } 
    } 
} 
  
int main(int argc, char const *argv[]) 
{ 
    int t;
    cin>>t;
    while(t--) {
      int n;
      cin>>n;
      int *arr1 = new int[n];
      int *arr2 = new int[n];
      for(int i=0;i<n;i++) {
        cin>>arr1[i];
      }
      for(int i=0;i<n;i++) {
        cin>>arr2[i];
      }
      Activitiy arr[n];
      for(int i=0;i<n;i++) {
        arr[i].start = arr1[i];
        arr[i].finish = arr2[i];
      }
      printMaxActivities(arr, n); 
      cout<<endl;
    }
    // Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}}; 
    // int n = sizeof(arr)/sizeof(arr[0]); 
    // printMaxActivities(arr, n); 
    return 0; 
} 