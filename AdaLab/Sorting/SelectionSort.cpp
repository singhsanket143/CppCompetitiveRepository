#include "iostream"
#include "limits"
using namespace std;

void selectionSort(int arr[], int n) {
    int min_idx =0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i; j < n; j++) {
            min_idx = (arr[j]<arr[min_idx])?j:min_idx;
        }
        swap(arr[i], arr[min_idx]);
    }
    return;
}

int main(int argc, char* argv[])
{

    int arr[5] = {4,5,1,2,1};
    selectionSort(arr, 5);
    for(int i=0;i<5;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
