#include "iostream"
using namespace std;

int power(int a, int b) {
    if(b == 0) {
        return 1;
    }
    int result = power(a, b/2);
    result *= result;
    if(b&1) {
        result *= a;
    }
    return result;
}

int main(int argc, char* argv[])
{
    cout<<power(2,5);

    return 0;
}
