#include "iostream"
using namespace std;

int median(int arr[], int n) {
    if(n%2==0) {
        return (arr[n/2]+arr[n/2-1])/2;
    } else {
        return arr[n/2];
    }
}
int getMedian(int arr1[], int arr2[], int n) {
    if(n<=0) {
        return -1;
    }
    if(n==1) {
        return (arr1[0]+arr2[0])/2;
    }
    if(n==2) {
        return (max(arr1[0], arr2[0])+min(arr1[1], arr2[1]))/2;
    }
    int m1 = median(arr1, n);
    int m2 = median(arr2, n);

    if(m1==m2)
        return m1;

    if(m1 < m2) {
        if(n%2 == 0) {
            return getMedian(arr1+ n/2 - 1,arr2, n - n/2 + 1);
        }
        return getMedian(arr1 + n/2, arr2, n-n/2);

    }
    if(n%2==0) {
        return getMedian(arr2+ n/2 -1,arr1, n - n/2 + 1);
    }
    return getMedian(arr2 + n/2, arr1, n-n/2);

}

int main(int argc, char* argv[])
{
    int n;
    cin>>n;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    cout<<getMedian(arr1, arr2, n)<<endl;
    return 0;
}
