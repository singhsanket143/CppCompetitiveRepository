#include "iostream"
using namespace std;

void UniqueNumber2(int arr[], int n) {
    int res = 0;
    for(int i=0;i<n;i++) {
        res ^= arr[i];
    }
    int i = 0;
    int temp = res;
    while(temp) {
        if(temp&1) {
            break;
        }
        i++;
        temp >>= 1;
    }
    int mask = (1<<i);
    int firstNumber = 0;
    for(int i=0;i<n;i++) {
        if(mask & arr[i]) {
            firstNumber ^= arr[i];
        }
    }
    int secondNumber = firstNumber ^ res;
    cout<<firstNumber<<" "<<secondNumber<<endl;
}
int main(int argc, char* argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    UniqueNumber2(arr, n);

    return 0;
}
