#include <bits/stdc++.h>
using namespace std;
#define MAX 100000000
vector<bool>isPrime (MAX,true);
unsigned primearray[5761459];
void gen_primes(){
	isPrime[0]=isPrime[1]=false;
	for(unsigned i=2;i*i<=MAX;i++){
		if(isPrime[i]){
			for(unsigned j=i;j*i<=MAX;j++) isPrime[i*j]=false;
		}
	}
	unsigned idx = 1;
	primearray[0]=2;
	for(unsigned i=3;i<=MAX;i+=2){
		if(isPrime[i]){
			primearray[idx++]=i;
		}
	}
}
int main() 
{
	gen_primes();
	int tc=100000000;
	for(int n=1;primearray[n-1]<99998953;n+=100)
	{
		cout<<(primearray[n-1])<<"\n";
	}
    cout<<(99998953);
	return 0;
}