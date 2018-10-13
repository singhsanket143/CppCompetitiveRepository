#include <bits/stdc++.h>
#define ll long long int
#define c 1000000007
using namespace std;

// ll modIterative(ll xa,ll xb){
// 	if(xb == 0){
// 		return 1;
// 	}

// 	if(xb%2 ==0){

// 		//Even
// 		return modIterative((xa*xa)%c,xb/2);
// 	}else{
// 		// Odd
// 		return ((xa%c)*(modIterative((xa*xa)%c,xb/2)))%c;
// 	}

// }

ll modIterative(ll a, ll b) {
	ll ans = 1;
	while(b!=0) {
		if((b&1)==1) {
			ans = ((ans%c) * (a%c))%c;
		}
		a = ((a%c)*(a%c))%c;
		b >>= 1;
	}
	return ans;
}

ll mod_inverse(ll n) {
	return modIterative(n, c-2);
}

ll binomial_btr(ll n, int r) {
	if(r == 0) {
		return 1;
	}
	// if(r == 1) {
	// 	return n%c;
	// }
	ll num = 1;
	for(int j = 2; j <= r; j++) {
		num = (num*(n-j+1))%c;
		num = (num*mod_inverse(j-1))%c;
	}
	return num;
}

// ll binomial(ll n, int r) {
// 	// if(r == 0) {
// 	// 	return 1;
// 	// }
// 	// if(r == 1) {
// 	// 	return 1;
// 	// }
// 	ll num = 1;
// 	// cout<<1<<" ";
// 	for(int j = 2; j <= r; j++) {
// 		num = (num)*((n-j+1))/(j-1);
// 		// cout<<num<<" ";
// 	}
// 	return num;
// }

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--) {
		ll n;
		int k;
		scanf("%lld", &n);
		scanf("%d", &k);
		n++;
		if(k==0) {
			printf("1\n");
			continue;
		}
		if(k > n) {
			printf("0\n");
			continue;
		}
		ll sum = 0;
		for(int i = 0; i <= k-1; i++) {
			ll b1 = binomial_btr(n-k+1, i+1+1);
			ll b2 = binomial_btr(k-1+1, i+1);
			ll x = ((b1*b2))%c;
			ll p = modIterative(2, i+1);
			ll val = ((x*p))%c;
			sum = ((sum+val))%c;
			// cout<<b1<<" "<<b2<<" "<<p<<" "<<val<<" "<<sum<<endl;
		}
		printf("%lld\n", sum);

	}
	// for(int i=1;i<=2;i++) {
		// binomial(4,2);
	// }

	
	return 0;
}
