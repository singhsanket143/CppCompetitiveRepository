#include<iostream>

void sort01(int *arr, int n) {
    int left = 0;
    int right = n-1;
    while(left <= right) {
        if(arr[left] == 0) {
            left++;
        } else if (arr[left] == 1) {
            std::swap(arr[left], arr[right]);
            right--;
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */

    int arr[] = {0,1,0,0,0,1,0,0,1,1,0,1};
    sort01(arr, 12);
    for(int i = 0; i < 12; i++) {
        std::cout<<arr[i]<<" ";
    }
    return 0;
}
