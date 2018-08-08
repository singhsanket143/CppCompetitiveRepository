#include "iostream"
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1, result = -1;
    while(left <= right) {
        int mid = (left + right) >> 1;
        if(arr[mid] == key) {
            result = mid;
            break;
        } else if(arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main(int argc, char* argv[])
{


    return 0;
}
