#include "iostream"
using namespace std;

int getIthBit(int n, int i) {
    return ((n & (1<<i))!=0)?1:0;
}
int main(int argc, char* argv[])
{
    int n, i;
    cin>>n>>i;
    cout<<getIthBit(13,2)<<endl;

    return 0;
}
