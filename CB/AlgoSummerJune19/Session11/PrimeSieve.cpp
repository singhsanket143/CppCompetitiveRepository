#include <iostream>
#include <vector>
#include "math.h"
using namespace std;


vector<int> primeSieve(int n) {
	vector<int> result;
	bool *arr = new bool[n+1]();
	for(int i=2;i<=sqrt(n);i++) {
		for(int j=i*2;j<=n;j+=i) {
			arr[j] = true;
		}
	}
	for(int i=2;i<=n;i++) {
		if(arr[i] == false) {
			result.push_back(i);
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	vector<int> v = primeSieve(50);
	for(int i=0;i<v.size();i++) {
		cout<<v[i]<<" ";
	}
	return 0;
}
