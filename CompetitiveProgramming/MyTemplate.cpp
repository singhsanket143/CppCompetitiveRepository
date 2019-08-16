#include<bits/stdc++.h>
#define pb push_back
#define len(n) n.length()
#define mp make_pair
#define forp(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n)    for(int i=0;i<n;i++)
#define ren(i,n)    for(int i=n-1;i>=0;i--)
#define forn(i,a,b) for(int i=a;i>=b;i--)
#define fre    freopen("in","r",stdin),freopen(y + ".out","w",stdout)
#define ff first
#define ss second
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<long long int>
#define o2(a,b) cout<<a<<" "<<b
#define all(n) n.begin(),n.end()
#define alll(n,i,j) n.begin()+i,n.begin()+j
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define mem(n,m) memset(n,m,sizeof(n))
#define bitc(n) __builtin_popcount(n)
#define mod 1000000007
#define mod2 1000000009
#define ma(m,n) m = max(m,n)
#define mi(m,n) m = min(m,n)
#define EPSILON 1e-6
#define PI 3.14159265358979323846
using namespace std;
typedef unsigned long long int ULL;
typedef long long int LL;
typedef vector<vector<LL> > mat;
#define N 100005
#define LD long double
static const int inf = 0x3f3f3f3f; static const long long infl = 0x3f3f3f3f3f3f3f3fLL;
template <typename T> T mulmod(T a,T b, T m){LL q=(LL)(((LD)a*(LD)b)/(LD)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template <typename T> T MOD(T a, T b) {return (a < b ? a : a % b);}
template <typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mulmod(x,p,m);p=mulmod(p,p,m);n>>=1;}return x;}
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
template <typename T> T add (T a, T b, T Mod) {a += b; return (a >= Mod ? a - Mod : a);}
template <typename T> T sub (T a, T b, T Mod) {a -= b; return (a < 0 ? a + Mod : a);}
