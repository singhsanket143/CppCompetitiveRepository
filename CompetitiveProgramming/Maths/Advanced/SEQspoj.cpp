#include "iostream"
#include "vector"
using namespace std;
#define ll long long int
#define mod 1000000000

vector<ll> a,b,c;
int k;

vector<vector<ll> > multiply(vector<vector<ll> > A, vector<vector<ll> > B) {
    vector<vector<ll> > C(k+1, vector<ll>(k+1));
    for(int i=1;i<=k;i++) {
        for(int j=1;j<=k;j++) {
            for(int x=1;x<=k;x++) {
                C[i][j] = ((C[i][j]) + ((A[i][x])*(B[x][j]))%mod)%mod;
            }
        }
    }
    return C;
}

vector<vector<ll> > pow(vector<vector<ll> > T, ll p) {
    if(p==1) {
        return T;
    }
    if(p&1) {
        return multiply(T, pow(T, p-1));
    } else {
        vector<vector<ll> >X = pow(T, p/2);
        return multiply(X,X);
    }
}

ll compute(ll n) {
    if(n==0) {
        return 0;
    }
    if(n<=k) {
        return b[n-1];
    }

    vector<ll> F1(k+1);
    for(int i=1;i<=k;i++) {
        F1[i] = b[i-1];
    }
    vector<vector<ll> > T(k+1, vector<ll>(k+1));
    // Prepare matrix
    for(int i=1;i<=k;i++) {
        for(int j=1;j<=k;j++) {
            if(i<k) {
                if(j==i+1) {
                    T[i][j] = 1;
                } else {
                    T[i][j] = 0;
                }
                continue;
            }
            T[i][j] = c[k-j];
        }
    }
    // Calculate T^n-1
    T = pow(T, n-1);
    // Multiply by F1
    ll res = 0;
    for(int i=1;i<=k;i++) {
        res = (res + (T[1][i]*F1[i])%mod)%mod;
    }
    return res;
}

int main(int argc, char* argv[])
{
    int t, n, num;
    cin>>t;
    while(t--) {
        cin>>k;
        for(int i=0;i<k;i++) {
            cin>>num;
            b.push_back(num);
        }
        for(int i=0;i<k;i++) {
            cin>>num;
            c.push_back(num);
        }
        cin>>n;
        cout<<compute(n)<<"\n";
        b.clear();
        c.clear();
    }
    return 0;
}
