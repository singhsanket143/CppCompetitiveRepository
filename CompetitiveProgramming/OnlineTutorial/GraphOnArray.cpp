#include <iostream>
#include <vector>
#include <list>
using namespace std;

int gcd(int a, int b) {
	if(b==0) {
		return a;
	}
	return gcd(b, a%b);
}

bool checkequal(int *arr, int n) {
	for(int i=1;i<n;i++) {
		if(arr[i]!=arr[i-1]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		list<int> ai;
		for(int i=0;i<n;i++) {
			ai.push_back(arr[i]);
		}
		vector<int> num;
		list<int> li;
		int ans = 0; // Whenever ans > 1 then we will break the process
		while(!ai.empty()) {
			num.push_back(ai.front());
			ai.pop_front();
			for(int i=0;i<num.size();i++) {
				while(!ai.empty()) { // Remaining elements which are not inserted in num vector
					int m = ai.front();
					ai.pop_front();
					if(gcd(m, num[i]) == 1) {
						num.push_back(m);
					} else {
						li.push_back(m);
					}
				}
				ai = li;
				li.clear();
			}
			ans++;
			num.clear();
			if(ans > 1) {
				break;
			}
		}
		if(ans == 1) {
			cout<<"0\n";
			for(int i=0;i<n;i++) {
				cout<<arr[i]<<" ";
			}
			cout<<"\n";
		} else if(checkequal(arr, n)) {
			if(arr[0] == 47) {
				arr[0] = 2;
			} else {
				arr[0] = 47;
			}
			cout<<"1\n";
			for(int i=0;i<n;i++) {
				cout<<arr[i]<<" ";
			}
			cout<<"\n";
		} else {
			arr[0] = 47;
			cout<<"1\n";
			for(int i=0;i<n;i++) {
				cout<<arr[i]<<" ";
			}
			cout<<"\n";
		}

	}
	return 0;
}
