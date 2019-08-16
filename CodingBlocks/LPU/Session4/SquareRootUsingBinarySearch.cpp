#include <iostream>
using namespace std;

int squareroot(int n) {
	int start = 1, end = n;
	int ans = -1;
	while(start <= end) {
		int mid = (start+end)/2;
		if(mid*mid == n) {
			return mid;
		} else if(mid*mid<n) {
			start = mid+1;
			ans = mid;
		} else {
			end = mid-1;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	cout<<squareroot(9);
	return 0;
}
