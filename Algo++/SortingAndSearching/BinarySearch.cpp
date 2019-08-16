#include "iostream"
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int lo = 0, hi = n-1;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] > key) {
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    return -1;
}

int main(int argc, char* argv[])
{
    int n, key;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cin>>key;
    std::cout << binarySearch(arr, n,key) << "\n";
    return 0;
}
