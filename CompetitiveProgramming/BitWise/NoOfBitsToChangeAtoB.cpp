#include "iostream"
using namespace std;
int main(int argc, char* argv[])
{
    int a,b;
    cin>>a>>b;
    int var = a^b;
    int count = 0;
    while(var) {
        var = var & (var-1);
        count++;
    }
    cout<<count;

    return 0;
}
