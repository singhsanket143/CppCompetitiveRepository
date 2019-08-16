#include<iostream>
#include<stdio.h>
using namespace std;

bool filterString(int *arr, int n, int k) {
    int i = 0;
    int result=0;
    while(n) {
        if (n&1){
            result+=arr[i];
        }
        i++;
        n >>= 1;
    }
    if(result == k) {
        return true;
    } else {
        return false;
    }
}

void generateSubsequences(int *arr, int n, int k) {
    int range = (1<<n) - 1;
    for(int i = 0 ; i <= range ; i++) {
        if(filterString(arr, i, k)) {
            cout<<"Yes";
            return;
        }
    }
    cout<<"No";
    return;
}

int main(int argc, char* argv[])
{

    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        cin>>n>>k;
        int *arr = new int[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        generateSubsequences(arr, n, k);
    }
    
    return 0;
}
