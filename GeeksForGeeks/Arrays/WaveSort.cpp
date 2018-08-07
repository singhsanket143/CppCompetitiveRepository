#include "iostream"
using namespace std;
int main(int argc, char* argv[])
{

    int arr[] = {1, 3, 4, 2, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i+=2) {
        if(i>0 and arr[i-1]>arr[i]) {
            swap(arr[i-1], arr[i]);
        }
        if(i<=n-2 and arr[i+1]>arr[i]) {
            swap(arr[i+1], arr[i]);
        }
    }
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}
