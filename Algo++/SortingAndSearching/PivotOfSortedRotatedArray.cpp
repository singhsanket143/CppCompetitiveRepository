#include "iostream"
using namespace std;

void pivot(int arr[], int n) {
    int lo = 0, hi = n-1;
    int ans = -1;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(mid>lo and arr[mid] < arr[mid-1]) {
            std::cout << mid - 1 << "\n";
            break;
        }
        if(mid<hi and arr[mid] > arr[mid+1]) {
            std::cout << mid << "\n";
            break;
        }
        if(arr[mid] >= arr[hi]) {
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
}
int main(int argc, char* argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    pivot(arr, n);
    return 0;
}
