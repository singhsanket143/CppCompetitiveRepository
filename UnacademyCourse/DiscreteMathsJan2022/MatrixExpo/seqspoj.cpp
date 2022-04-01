#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
#define mod 1000000000
ll k;
std::vector<int> a, b, c;

std::vector<std::vector<ll> > multiply(std::vector<std::vector<ll> > &A, std::vector<std::vector<ll> > &B) {
    std::vector<std::vector<ll> > res(k+1, std::vector<ll> (k+1));
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= k; j++) {
            for(int x = 1; x <= k; x++) {
                res[i][j] = (res[i][j] + (A[i][x]*B[x][j])%mod)%mod;
            }
        }
    }
    return res;
}

std::vector<std::vector<ll> > pow_(std::vector<std::vector<ll> > T, ll p) {
    if(p == 1) {
        return T;
    }
    if(p&1) {
        std::vector<std::vector<ll> > y = pow_(T, p-1);
        return multiply(T, y);
    } else {
        std::vector<std::vector<ll> > x = pow_(T, p/2);
        return multiply(x, x);
    }
}
ll calc(ll n) {
    if(n == 0) return 0;
    if(n <= k) return b[n-1];

    std::vector<ll> f1(k+1);
    for(int i = 1; i <= k; i++) {
        f1[i] = b[i-1];
    } 

    // start implementing transformation matrix
    std::vector<std::vector<ll> > T (k+1, std::vector<ll> (k+1, 0));
    for(int i = 1; i<= k; i++) {
        for(int j = 1; j <= k; j++) {
            if(i < k) {
                if(j == i+1) T[i][j] = 1;
                continue;
            }
            T[i][j] = c[k-j];
            
        }
    }
    T = pow_(T, n-1);
    ll res = 0;
    for(int i = 1; i <= k; i++) {
        res = (res + (T[1][i]*f1[i])%mod)%mod;
    }
    return res;

}

int main(int argc, char const *argv[])
{
    ll t, n, num;
    std::cin>>t;
    while(t--) {
        std::cin>>k;
        for(int i = 0; i < k; i++) {
            std::cin>>num;
            b.push_back(num);
        }
        for(int i = 0; i < k; i++) {
            std::cin>>num;
            c.push_back(num);
        }
        std::cin>>n;
        std::cout<<"Value is "<<calc(n)<<"\n";
        b.clear();
        c.clear();
    }

    return 0;
}
