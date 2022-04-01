#include <iostream>
#define ll long long int
using namespace std;

void multiply(ll A[2][2], ll M[2][2]) {
    ll a = A[0][0]*M[0][0] + A[0][1]*M[1][0];
    ll b = A[0][0]*M[0][1] + A[0][1]*M[1][1];
    ll c = A[1][0]*M[0][0] + A[1][1]*M[1][0];
    ll d = A[1][0]*M[0][1] + A[1][1]*M[1][1];
    A[0][0] = a;
    A[0][1] = b;
    A[1][0] = c;
    A[1][1] = d;
}

void power(ll A[2][2], ll n) {
    if(n == 0 or n == 1) return;
    power(A, n/2);
    multiply(A, A);
    if(n%2!=0) {
        ll M[2][2] = {{0,1}, {1,1}};
        multiply(A, M);
    }
}
ll fib(ll n) {
    ll A[2][2] = {{0,1}, {1,1}};
    if(n == 0) return 0;
    power(A, n-1);
    ll f[2] = {0,1};
    return A[1][0]*f[0]+A[1][1]*f[1];
}

int main(int argc, char const *argv[])
{
    /* code */
    std::cout<<fib(7);
    return 0;
}
