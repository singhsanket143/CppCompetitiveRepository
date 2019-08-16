#include <iostream>
#define inf 1e9
using namespace std;
typedef long long int ll;
int gcd(int a, int b) 
{ 
    while (a != b) { 
        if (a > b)         
            a = a - b;         
        else        
            b = b - a;         
    } 
    return a; 
} 

int main(int argc, char const *argv[])
{
	ll t;
	scanf("%lld", &t);
	while(t--) {
		ll n;
		scanf("%lld", &n);
		int *arr = new int[n];
		bool status = false;
		for(int i=0;i<n;i++) {
			scanf("%d", &arr[i]);
		}
		ll el = -inf;
		el=arr[0];
		for(int i=1;i<n;i++) {
			if(arr[i] == arr[i-1]) {
				status = true;
			}
			el = (arr[i]>el)?arr[i]:el;
		}
		// if(status and arr[0]==-1) {
		// 	printf("inf\n");
		// 	delete [] arr;
		// 	isPrime(10);
		// 	continue;
		// } 
		ll low = -1, hi = -1;
		bool b=false;
		for(int i=0;i<n;i++) {
			if(arr[i]==-1)
				continue;
			if(low==-1){
				low=i;
				continue;
			}
			if(arr[i]-arr[low] == i-low) {
				continue;
			}
			if(arr[i]-arr[low] > i-low) {
				printf("impossible\n");
				b=true;
				break;
			} 

			if(arr[low]>arr[low]-arr[i]+i-low) {
				b=true;
				printf("impossible\n"); 
				break;
			}
			if(hi==-1){
				hi = arr[low]-arr[i]+i-low;
			} else {
				hi = gcd(hi, arr[low]-arr[i]+i-low);
			}
			if(hi<el){
				printf("impossible\n"); 
				b=true;

				break;
			}
		}
		if(hi==-1 and b==false) {
			printf("inf\n"); 
		}else if(b==false){
			printf("%lld\n", hi); 
		}
		delete [] arr;
	}
	return 0;
}