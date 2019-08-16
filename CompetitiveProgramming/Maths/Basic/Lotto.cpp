#include "iostream"
using namespace std;
int main(int argc, char* argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(int);
    for(int i = 0; i < n - 5; i++) {
        for(int j = i+1; j < n - 4; j++) {
            for(int k = j+1; k < n -3; k++) {
                for(int l = k+1; l < n - 2; l++) {
                    for(int m = l+1; m < n - 1; m++) {
                        for(int o = m+1; o < n; o++) {
                            cout<<arr[i]<<", "<<arr[j]<<", "<<arr[k]<<", "<<arr[l]<<", "<<arr[m]<<", "<<arr[o]<<endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
