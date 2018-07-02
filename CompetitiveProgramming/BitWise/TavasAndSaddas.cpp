#include "iostream"
#include "cstring"
using namespace std;
typedef long long ll;
int main(int argc, char* argv[])
{
    char a[20];
    cin>>a;
    int len = strlen(a);
    ll answer = 0;
    answer = (1<<len)-2;
    for(int i=len-1, pos =0; i>=0;i--,pos++) {
        if(a[i]=='7') {
            answer+=(1<<pos);
        }
    }
    std::cout << answer + 1 << "\n";

    return 0;
}
