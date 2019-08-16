#include "iostream"
using namespace std;
void setithBit(int &n, int i) {
    n = n | (1<<i);
}
int main(int argc, char* argv[])
{
    int n, i;
    cin >> n >> i;
    setithBit(n, i);
    cout<<n<<endl;
    return 0;
}
