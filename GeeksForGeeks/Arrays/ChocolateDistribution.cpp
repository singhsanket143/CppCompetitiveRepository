#include "iostream"
#include "algorithm"
#include "limits"
using namespace std;

int chocolateDiff(int arr[], int n, int students) {

    if(n == 0 or students == 0) {
        return 0;
    }
    sort(arr, arr+n);
    if(students > n) {
        return -1;
    }
    int min_diff = INT_MAX;
    int first = 0, last = 0;
    for(int i=0;i+students-1<n;i++) {
        int diff = arr[i+students-1] - arr[i];
        if(diff < min_diff) {
            min_diff = diff;
            first = i;
            last = i+m-1;
        }
    }
    return min_diff;
}

int main(int argc, char* argv[])
{


    return 0;
}
