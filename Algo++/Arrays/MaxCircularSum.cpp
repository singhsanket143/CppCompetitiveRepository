#include "iostream"
using namespace std;

int kadane(int arr[], int n) {
    int max_sum=0, curr_Sum=0;
    for(int i=0;i<n;i++) {
        curr_Sum+=arr[i];
        if(curr_Sum<0) {
            curr_Sum = 0;
        }
        max_sum = max(max_sum,curr_Sum);
    }
    return max_sum;
}

int main(int argc, char* argv[])
{
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int candidate1 = kadane(arr, n);
        int cumulative_sum = 0;
        for(int i=0;i<n;i++) {
            cumulative_sum+=arr[i];
            arr[i]*=(-1);
        }
        int removal = kadane(arr, n);
        int candidate2 = cumulative_sum - ((-1)*removal);

        cout<<max(candidate1,candidate2)<<endl;
    }

    return 0;
}
