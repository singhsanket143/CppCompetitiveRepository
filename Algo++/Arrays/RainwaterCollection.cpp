#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char* argv[])
{

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int left[n];
    int right[n];
    int left_max = INT_MIN;
    int right_max = INT_MIN;
    for(int i=0;i<n;i++) {
        left[i] = max(left_max, arr[i]);
        left_max = (left[i]>left_max)?left[i]:left_max;
    }
    for(int i=n-1;i>=0;i--) {
        right[i] = max(right_max, arr[i]);
        right_max = (right[i]>right_max)?right[i]:right_max;
    }
    int result = 0;
    
    for(int i=0;i<n;i++) {
        result+= min(left[i], right[i]) - arr[i];
    }
    cout<<result;
    return 0;
}
