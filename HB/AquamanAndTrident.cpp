
#include <iostream>
#include<math.h>
using namespace std;
int nthpower(int num, int n, int k, double osf, string str) {
    if(osf == num) {
        cout<<str<<endl;
        return 1;
    }
    if (osf > num) {
            return 0;
        }
    if (pow(k, n) > num) {
        return 0;
    }
    int count = 0;
    count += nthpower(num, n, k + 1, osf + pow(k, n), str + to_string(k) + " ");
    count += nthpower(num, n, k + 1, osf, str);
    return count;
}
int main(int argc, char const *argv[])
{
    /* code */
    int n,k;
    cin>>n>>k;
    cout<<nthpower(n, k, 1, 0, "")<<endl;
    return 0;
}
