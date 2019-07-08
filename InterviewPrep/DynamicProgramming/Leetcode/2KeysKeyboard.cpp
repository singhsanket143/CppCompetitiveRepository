#include <iostream>
#include <vector>
using namespace std;
int sieve[10005];
#define MAX 10005
vector<bool>isPrime (MAX, true);
unsigned primearray[10005];
vector<int> result;
void gen_primes() {
	isPrime[0] = isPrime[1] = false;
	for (unsigned i = 2; i * i <= MAX; i++) {
		if (isPrime[i]) {
			for (unsigned j = i; j * i <= MAX; j++) isPrime[i * j] = false;
		}
	}
	unsigned idx = 1;
	primearray[0] = 2;
	result.push_back(2);
	for (int i = 3; i <= MAX; i += 2) {
		if (isPrime[i]) {
			primearray[idx++] = i;
			result.push_back(i);
		}
	}
}
int minSteps(int n) {
	if (isPrime[n] == true) {
		return n;
	}
	int retval = 0, i = 0;
	while (n > 1) {
		if(isPrime[n] == true) {
			retval+=n;
			break;
		}
		int num = result[i], temp = 1;
		while (n > 1 and n % num == 0) {
			n = n / num;
			temp = temp * num;
		}
		// cout<<n<<" "<<num<<" "<<temp<<endl;
		retval += temp;
		i++;
	}
	return retval;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	gen_primes();
	cout<<minSteps(n);
	return 0;
}
