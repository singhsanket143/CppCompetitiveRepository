#include "iostream"
#include "cstring"
using namespace std;

int subarraySum(int arr[], int n, int sum) {
    int curr_sum = arr[0], start = 0, i;
    for(i = 1; i <= n; i++) {
        while(curr_sum > sum and start < i-1) {
            curr_sum -= arr[start];
            start++;
        }
        if(curr_sum == sum) {
            cout<<"Subarray exist from "<<start<<" to "<<i-1<<endl;
            return 1;
        }
        if(i < n){
            curr_sum += arr[i];
        }
    }

    cout<<"No Subarray was found!!"<<endl;
    return 0;
}

int main(int argc, char* argv[])
{
    int n, sum;
    cin>>n>>sum;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    subarraySum(arr, n, sum);
    return 0;
}
