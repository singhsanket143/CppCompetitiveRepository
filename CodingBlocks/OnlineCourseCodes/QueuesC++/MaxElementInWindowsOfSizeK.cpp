#include <iostream>
#include <deque>
using namespace std;
void printKMax(int *arr, int n, int k) {
    deque<int> q;
    int i;
    for(i = 0; i < k;i++) {
        while((!q.empty()) and arr[i] >= arr[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    for(; i < n; i++) {
        cout<<arr[q.front()]<<" ";
        while((!q.empty()) and q.front() <= i - k) {
            q.pop_front();
        }
        while((!q.empty()) and arr[i] >= arr[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<arr[q.front()];
} 
  
int main() 
{ 
    
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }  
    int k;
    cin>>k; 
    printKMax(arr, n, k); 
    return 0; 
} 