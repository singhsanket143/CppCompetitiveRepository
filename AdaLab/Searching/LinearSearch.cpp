/*
By Sanket Singh
*/
#include "iostream"
#include "limits"
#include "chrono"
#include "time.h"
using namespace std;
using namespace std::chrono;
int linearSearch(int arr[], int n, int key) {
    int result = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            result = i;
            break;
        }
    }
    return result;
}

int main(int argc, char* argv[])
{

    int max = 1000, min = 1;
    int range = max - min + 1;
    int avg_result[30] = {0};
    int best_result[30] = {0};
    int worst_result[30] = {0};

    int size[33] = {10, 50, 100, 250, 500, 750, 1000,1200, 1500, 2000, 5000, 6000, 7500,10000, 20000, 25000, 30000,45000, 50000, 75000, 85000, 95000, 100000, 150000, 250000, 400000, 500000,750000, 900000, 1000000, 10000000, 100000000, 1000000000};
    // for(int i = 0; i < 20; i++) {
    //     srand(time(0));
    //     int arr[size[i]];
    //     for(int j = 0; j < size[i]; j++) {
    //         arr[j] = (rand()%range)+min;
    //     }
    //     auto start = high_resolution_clock::now();
    //     binarySearch(arr, size[i], (rand()%range)+min);
    //     auto stop = high_resolution_clock::now();
    //     auto duration = duration_cast<microseconds>(stop - start);
    //     cout<<duration.count()<<", ";
    // }
    // cout<<endl;
    //
    for(int i = 0; i < 33; i++) {
        srand(time(0));
        int arr[size[i]];
        for(int j = 0; j < size[i]; j++) {
            arr[j] = j+1;
        }
        auto start = high_resolution_clock::now();
        int r=(rand()%size[i]);
        linearSearch(arr, size[i], r);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<duration.count()<<" ,";
    }
    cout<<endl;
    //
    // for(int i = 0; i < 20; i++) {
    //     srand(time(0));
    //     int arr[size[i]];
    //     for(int j = 0; j < size[i]; j++) {
    //         arr[j] = size[i] - j + 1;
    //     }
    //     auto start = high_resolution_clock::now();
    //     binarySearch(arr, size[i]);
    //     auto stop = high_resolution_clock::now();
    //     auto duration = duration_cast<microseconds>(stop - start);
    //     cout<<duration.count()<<" ,";
    // }
    // cout<<endl;
    return 0;
}
