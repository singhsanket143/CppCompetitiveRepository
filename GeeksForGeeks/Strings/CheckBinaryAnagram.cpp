#include "bits/stdc++.h"
#define ull unsigned long long int
using namespace std;
int main(int argc, char* argv[])
{
    ull a = 8, b = 4;
    vector<int> v;
    if(__builtin_popcount(a) == __builtin_popcount(b)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
