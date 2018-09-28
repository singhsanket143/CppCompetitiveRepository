#include <iostream>
#include "math.h"
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        ll sum_of_squares = (n*(n+1)*(2*n+1))/6;
        ll square_of_sum = (n*(n+1))/2;
        square_of_sum *= square_of_sum;
        cout<<abs(square_of_sum-sum_of_squares)<<"\n";
    }
    return 0;
}
