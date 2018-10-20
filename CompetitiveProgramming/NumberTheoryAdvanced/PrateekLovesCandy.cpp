#include <iostream>
#include <vector>
using namespace std;
#define MAX 10000000
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
    
	for(int i=3;i<=MAX;i+=2){
		if(isPrime[i]){
			primearray[idx++]=i;
		}     
	}
}

int main(int argc, char const *argv[])
{

    gen_primes();
    
    int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		cout<<primearray[n-1]<<endl;
	}
	return 0;
}
