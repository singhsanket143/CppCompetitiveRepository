#include "iostream"
using namespace std;

void InsertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int j = i-1;
        while(j>=0 and arr[j]>arr[i]) {
            j--;
        }
        j++;
        int temp = arr[i];
        for(int var = i - 1; var >= j; var--) {
            arr[var+1] = arr[var];
        }
        arr[j] = temp;
    }
    return;
}

int main(int argc, char* argv[])
{

    int arr[5] = {-1, -2, -3, -4, -5};
    InsertionSort(arr, 5);
    for(int i=0;i<5;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
