#include "iostream"
using namespace std;

int fastSetBits(int n) {
    int count = 0;
    while(n) {
        count++;
        n = n & (n-1);
    }
    return count;
}
int main(int argc, char* argv[])
{

    int n;
    cin>>n;
    cout<<fastSetBits(n)<<endl;
    return 0;
}
