#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{

    int t;
    int n;
    cin>>t;
    while(t-- > 0) {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int currentSum = 0;
        int maxSum = 0;
        for(int i=0;i<n;i++) {
            currentSum+=arr[i];
            if(currentSum < 0) {
                currentSum = 0;
            }
            maxSum = max(currentSum, maxSum);
        }
        cout<<maxSum<<endl;
    }
    return 0;
}
