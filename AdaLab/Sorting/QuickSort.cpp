/*
By Sanket Singh
*/
#include "iostream"
#include "chrono"
#include "time.h"
using namespace std;
using namespace std::chrono;

int partition(int *arr, int start, int end) {
	int i = start - 1;
	int j = start;
	int pivot = arr[end];
	for(; j < end; j++) {
		if(arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[end]);
	return i+1;
}

void quickSort(int *arr, int start, int end) {
	if(start >= end){
		return;
	}
	int pivot = partition(arr, start, end);
	quickSort(arr, start, pivot-1);
	quickSort(arr, pivot+1, end);

}

int main(int argc, char const *argv[])
{
	int max = 1000, min = 1;
    int range = max - min + 1;
    int avg_result[30] = {0};
    int best_result[30] = {0};
    int worst_result[30] = {0};
    int size[30] = {10, 50, 100, 250, 500, 750, 1000,1200, 1500, 2000, 5000, 6000, 7500,10000, 20000, 25000, 30000,45000, 50000, 75000, 85000, 95000, 100000, 150000, 250000, 400000, 500000,750000, 900000, 1000000};
    for(int i = 0; i < 20; i++) {
        srand(time(0));
        int arr[size[i]];
        for(int j = 0; j < size[i]; j++) {
            arr[j] = (rand()%range)+min;
        }
        auto start = high_resolution_clock::now();
        quickSort(arr, 0, size[i]-1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<duration.count()<<", ";
    }
    cout<<endl;
    //
    // for(int i = 0; i < 30; i++) {
    //     srand(time(0));
    //     int arr[size[i]];
    //     for(int j = 0; j < size[i]; j++) {
    //         arr[j] = j+1;
    //     }
    //     auto start = high_resolution_clock::now();
    //     InsertionSort(arr, size[i]);
    //     auto stop = high_resolution_clock::now();
    //     auto duration = duration_cast<microseconds>(stop - start);
    //     cout<<duration.count()<<" ,";
    // }
    // cout<<endl;
    //
    // for(int i = 0; i < 20; i++) {
    //     srand(time(0));
    //     int arr[size[i]];
    //     for(int j = 0; j < size[i]; j++) {
    //         arr[j] = size[i] - j + 1;
    //     }
    //     auto start = high_resolution_clock::now();
    //     quickSort(arr, 0, size[i]-1);
    //     auto stop = high_resolution_clock::now();
    //     auto duration = duration_cast<microseconds>(stop - start);
    //     cout<<duration.count()<<" ,";
    // }
    // cout<<endl;
	return 0;
}
