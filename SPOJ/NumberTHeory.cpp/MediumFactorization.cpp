#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define MAX 11111111
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

void factorize(int m) {
	int i=0;
	int p = primearray[0];
	while(p*p<=m) {
		if(m%p == 0) {
			
			while(m%p==0) {
				m = m/p;
				printf(" x %d", p);
			}
		}
		i++;
		p = primearray[i];

	}
	if(m!=1) {
			printf(" x %d", m);
	}
    printf("\n");
	return ;

}

int main(int argc, char const *argv[])
{
	gen_primes();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	while(scanf("%d", &n)!=EOF) {
		printf("1");
		factorize(n);
	}
	return 0;
}
