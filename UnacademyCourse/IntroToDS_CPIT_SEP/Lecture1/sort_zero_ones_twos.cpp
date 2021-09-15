#include<iostream>

void sort012(int *arr, int n) {
    int l = 0, r = n-1, m = 0;
    while(m <= r) {
        if(arr[m] == 0) {
            std::swap(arr[m], arr[l]);
            l++;
            m++;
        } else if(arr[m] == 1) {
            m++;
        } else {
            std::swap(arr[m], arr[r]);
            r--;
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int arr[] = {0,1,0,2,0,1,2,0,2,2,0,1};
    sort012(arr, 12);
    for(int i = 0; i < 12; i++) {
        std::cout<<arr[i]<<" ";
    }
    return 0;
}
