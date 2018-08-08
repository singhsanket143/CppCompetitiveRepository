#include "iostream"
#include "chrono"
using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n) {
    bool check = true;
    for(int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1]) {
            check = false;
            break;
        }
    }
    if(check) {
        return;
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j+1], arr[j]);
            }
        }
    }
    return;
}

int main(int argc, char* argv[])
{

    int arr[100];
    int max = 1000, min = 1;
    for(int i=0;i<100;i++) {
        arr[i] = i+1;
    }
    auto start = high_resolution_clock::now();
    bubbleSort(arr, 100);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<duration.count()<<endl;
    // for(int i=1;i<100;i++) {
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}
