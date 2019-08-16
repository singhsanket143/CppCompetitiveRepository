#include "iostream"
using namespace std;

float sqrtPercision(int no, int p) {
    int lo = 0, hi = no, ans = -1;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(mid*mid == no) {
            ans = mid;
            break;
        } else if (mid*mid < no) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid -1;
        }
    }
    // fractional part
    float inc = 0.1;
    float result = ans;
    for(int i=0;i<p;i++) {
        while(result*result<=no) {
            result+=inc;
        }
        result = result - inc;
        inc/=10;

    }
    return result;
}
int main(int argc, char* argv[])
{
    int n,p;
    cin>>n;
    cin>>p;
    cout<<sqrtPercision(n,p);
    return 0;
}
