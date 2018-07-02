#include "iostream"
using namespace std;
int main(int argc, char* argv[])
{

    int a,b;
    cin>>a>>b;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<a<<" and "<<b<<endl;
    return 0;
}
