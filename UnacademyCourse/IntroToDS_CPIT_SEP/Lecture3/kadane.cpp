#include<iostream>
#include<limits.h>

int max_sum_subarray(int *arr, int n) {
    // TC - O(n), SC - O(1)
    int result = INT_MIN;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum = sum + arr[i];
        if(result < sum) {
            result = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
