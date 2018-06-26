#include "iostream"
using namespace std;
int main(int argc, char* argv[])
{
    int n;
    cin>>n;
    int arr[n];
    int x = 0;
    int ans1=0;
    int ans2=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        x^=arr[i];
    }
    int set_bit_no = (x) & ~(x-1);
    for(int i=0;i<n;i++) {
        if(arr[i]&set_bit_no) {
            ans1^=arr[i];
        } else {
            ans2^=arr[i];
        }
    }
    if(ans1>ans2) {
        cout<<ans1<<" "<<ans2<<endl;
    } else {
        cout<<ans2<<" "<<ans1<<endl;
    }
    return 0;
}
