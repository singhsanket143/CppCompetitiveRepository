/*
By Sanket Singh
*/
#include "iostream"
#include "chrono"
#include "time.h"
using namespace std;
using namespace std::chrono;

void merge(int *arr, int start, int end) {
	int mid = (start+end)/2;
	int i = start, j = mid+1, k = start;
	int temp[10000];

	while(i <= mid and j <= end) {
		if(arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	while(i <= mid) {
		temp[k++] = arr[i++];
	}
	while(j <= end) {
		temp[k++] = arr[j++];
	}
	for(int i = start; i <= end; i++) {
		arr[i] = temp[i];
	}

}

void mergeSort(int *arr, int start, int end) {
	if(start >= end) {
		return;
	}
	int mid = (start+end)/2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid+1, end);
	merge(arr, start, end);
}

// void printArray(int A[], int size)
// {
//     for (int i = 0; i < size; i++)
//         printf("%d ", A[i]);
 
//     printf("\n");
// }

// void join(int arr[], int left[], int right[],
//           int l, int m, int r)
// {
//     int i; // Used in second loop
//     for (i = 0; i <= m - l; i++)
//         arr[i] = left[i];
 
//     for (int j = 0; j < r - m; j++)
//         arr[i + j] = right[j];
// }
 
// // Function to store alternate elemets in left
// // and right subarray
// void split(int arr[], int left[], int right[],
//           int l, int m, int r)
// {
//     for (int i = 0; i <= m - l; i++)
//         left[i] = arr[i * 2];
 
//     for (int i = 0; i < r - m; i++)
//         right[i] = arr[i * 2 + 1];
// }
// void generateWorstCase(int arr[], int l, int r)
// {
//     if (l < r)
//     {
//         int m = l + (r - l) / 2;
 
//         // create two auxillary arrays
//         int left[m - l + 1];
//         int right[r - m];
 
//         // Store alternate array elements in left
//         // and right subarray
//         split(arr, left, right, l, m, r);
 
//         // Recurse first and second halves
//         generateWorstCase(left, l, m);
//         generateWorstCase(right, m + 1, r);
 
//         // join left and right subarray
//         join(arr, left, right, l, m, r);
//     }
// }


int main(int argc, char const *argv[])
{
	int arr[100000];
	int max = 1000, min = 1;
    int range = max - min + 1;
    int avg_result[30] = {0};
    int best_result[30] = {0};
    int worst_result[30] = {0};
    int size[30] = {10, 50, 100, 250, 500, 750, 1000,1200, 1500, 2000, 5000, 6000, 7500,10000, 20000, 25000, 30000,45000, 50000, 75000, 85000, 95000, 100000, 150000, 250000, 400000, 500000,750000, 900000, 1000000};
    // for(int i = 0; i < 14; i++) {
    //     srand(time(0));
        
    //     for(int j = 0; j < size[i]; j++) {
    //         arr[j] = (rand()%range)+min;
    //     }
    //     auto start = high_resolution_clock::now();
    //     mergeSort(arr, 0, size[i] - 1);
    //     auto stop = high_resolution_clock::now();
    //     auto duration = duration_cast<microseconds>(stop - start);
    //     cout<<duration.count()<<", ";
        
    // }
    // cout<<endl;
    //
    // for(int i = 0; i < 14; i++) {
    //     srand(time(0));
        
    //     for(int j = 0; j < size[i]; j++) {
    //         arr[j] = j+1;
    //     }
    //     auto start = high_resolution_clock::now();
    //     mergeSort(arr, 0, size[i]-1);
    //     auto stop = high_resolution_clock::now();
    //     auto duration = duration_cast<microseconds>(stop - start);
    //     cout<<duration.count()<<" ,";
    // }
    // cout<<endl;
    
    // for(int i = 0; i < 14; i++) {
    //     srand(time(0));
    //     int arr[size[i]];
    //     int temp[size[i]];
    //     generateWorstCase(temp, 0, size[i] - 1);

    //     for(int j = 0; j < size[i]; j++) {
    //         arr[j] = temp[j];
    //     }
    //     auto start = high_resolution_clock::now();
    //     // printArray(arr, size[i]);
    //     // cout<<endl;
    //     mergeSort(arr, 0, size[i]-1);
    //     auto stop = high_resolution_clock::now();
    //     // printArray(arr, size[i]);
    //     // cout<<endl;
    //     auto duration = duration_cast<microseconds>(stop - start);
    //     cout<<duration.count()<<" ,";
    // }
    // cout<<endl;
	return 0;
}
