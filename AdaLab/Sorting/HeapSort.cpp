#include "iostream"
#include "chrono"
#include "time.h"
using namespace std;
using namespace std::chrono;

void heapify(int *arr, int n, int i) {
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if(left < n and arr[left] > arr[largest]) {
		largest = left;
	}
	if(right < n and arr[right] > arr[largest]) {
		largest = right;
	}
	if(largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
	}
 
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(int argc, char const *argv[])
{
	int max = 1000, min = 1;
    int range = max - min + 1;
    int avg_result[30] = {0};
    int best_result[30] = {0};
    int worst_result[30] = {0};
    int size[30] = {10, 50, 100, 250, 500, 750, 1000,1200, 1500, 2000, 5000, 6000, 7500,10000, 20000, 25000, 30000,45000, 50000, 75000, 85000, 95000, 100000, 150000, 250000, 400000, 500000,750000, 900000, 1000000};
    // for(int i = 0; i < 30; i++) {
    //     srand(time(0));
    //     int arr[size[i]];
    //     for(int j = 0; j < size[i]; j++) {
    //         arr[j] = (rand()%range)+min;
    //     }
    //     auto start = high_resolution_clock::now();
    //     heapSort(arr, size[i]);
    //     auto stop = high_resolution_clock::now();
    //     auto duration = duration_cast<microseconds>(stop - start);
    //     cout<<duration.count()<<", ";
    // }
    // cout<<endl;
    //
    // for(int i = 0; i < 30; i++) {
    //     srand(time(0));
    //     int arr[size[i]];
    //     for(int j = 0; j < size[i]; j++) {
    //         arr[j] = 100;
    //     }
    //     auto start = high_resolution_clock::now();
    //     heapSort(arr, size[i]);
    //     auto stop = high_resolution_clock::now();
    //     auto duration = duration_cast<microseconds>(stop - start);
    //     cout<<duration.count()<<" ,";
    // }
    // cout<<endl;
    //
    for(int i = 0; i < 30; i++) {
        srand(time(0));
        int arr[size[i]];
        for(int j = 0; j < size[i]; j++) {
            arr[j] = size[i] - j + 1;
        }
        auto start = high_resolution_clock::now();
        heapSort(arr, size[i]);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<duration.count()<<" ,";
    }
    cout<<endl;
	return 0;
}
