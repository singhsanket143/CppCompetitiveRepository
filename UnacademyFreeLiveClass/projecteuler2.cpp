#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;

	for(int i = 0; i < t; i++) {
		long long int N;
		cin>>N;
		long long int result = 0, prev = 0, curr = 2;

		while(curr < N) {
			result += curr;
			long long int new_val = 4*curr + prev;
			prev = curr;
			curr = new_val;
		}
		cout<<result<<endl;
	}
}