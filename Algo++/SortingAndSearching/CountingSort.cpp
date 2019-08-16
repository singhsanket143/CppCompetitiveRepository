#include "iostream"
using namespace std;
void countingSort(int arr[], int n, int range) {
    int freq[range+1];
    for(int i=0;i<range+1;i++) {
        freq[i] = 0;
    }
    for(int i=0;i<n;i++) {
        freq[arr[i]]++;
    }
    int i = 0, freqI = 0;
    while(i<n) {
        if(freq[freqI] == 0) {
            freqI++;
            continue;
        }
        freq[freqI]--;
        arr[i++] = freqI;
    }
    return;
}
int main(int argc, char* argv[])
{
    int n;
    cin>>n;
    int arr[n];
    int range = 0;
    for(int i = 0;i<n;i++) {
        cin>>arr[i];
        range = (arr[i]>range)?arr[i]:range;
    }
    countingSort(arr, n, range);
    for(int i = 0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
