#include <bits/stdc++.h>
using namespace std;
#define MAX 100000001
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
inline unsigned scan()
    {
        unsigned z=0;
        char c;
        do{ c=getchar_unlocked(); } while(c<'0');
        for(;c>='0';c=getchar_unlocked()) z = (z<<3) + (z<<1) + (c&15);
        return z;
    }
inline void pf(unsigned n) {
  char stack[20];
  int top = 0;
  if(n == 0) {
    putchar_unlocked('0');
  } else {
    while(n > 0) {
      stack[top++] = n % 10 + '0';
      n /= 10;
    }
    while(top > 0) {
      putchar_unlocked(stack[--top]);
    }
  }
  putchar_unlocked('\n');
}
int main() 
{
	gen_primes();
	int tc,n;
	scanf("%d",&tc);
	while(tc--)
	{
		n=scan();
		pf(primearray[n-1]);
	}
	return 0;
}