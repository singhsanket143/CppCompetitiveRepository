#include "iostream"
using namespace std;

int lower_bound(int arr[], int n, int k) {
    int lo = 0, hi = n - 1, ans = -1;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(arr[mid] == k) {
            ans = mid;
            hi = mid - 1;
        } else if(arr[mid] > k) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
int upper_bound(int arr[], int n, int k) {
    int lo = 0, hi = n - 1, ans = -1;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(arr[mid] == k) {
            ans = mid;
            lo = mid + 1;
        } else if(arr[mid] > k) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
int main(int argc, char* argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int t, k;
    cin>>t;
    while(t-- > 0) {
        cin>>k;
        std::cout << lower_bound(arr, n, k) << " " << upper_bound(arr, n, k) << "\n";
    }

    return 0;
}
