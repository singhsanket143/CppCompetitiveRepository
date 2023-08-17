#include <iostream>
#include <vector>
using namespace std;

bool cmp(int a, int b) {

    return a > b;
    // 10 > 14 -> false -> picked b (second argument)
    // 14 > 10 -> true -> picked a (first argument)
    // 5 > 5 -> false  -> 5
}

bool oldcmp(int a, int b) {
    return a < b; 
    // 10 < 14 -> true -> picked a (first argument)
    // 14 < 10 -> false -> picked b(second argument)
}

int main() {

    vector<int> v = {5,4,1,-1,9,8,16,21,12};
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<"\n";
    }
    return 0;
}

// a , b-> a < b -> we picked a
// 10 < 14 -> true

