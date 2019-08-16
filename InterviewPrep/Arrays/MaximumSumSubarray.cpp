#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size)
{
    int max_so_far = a[0];
    int curr_max = a[0];

    for (int i = 1; i < size; i++) {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int maxSumSub(int *inp, int n) {
    int result = -INT_MAX;
    for (int i = 0; i < n; i++) {
        int sum = inp[i];
        result = max(sum, result);
        for (int j = i + 1; j < n; j++) {
            sum += inp[j];
            result = max(sum, result);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxSumSub(arr, n);
}
