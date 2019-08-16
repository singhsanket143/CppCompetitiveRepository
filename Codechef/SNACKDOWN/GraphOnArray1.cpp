#include <iostream>
#include <list>
#include <vector>
using namespace std;

int gcd(int a, int b) {
		if (b == 0)
			return a;
		a %= b;
		return gcd(b, a);
}

bool checkequal(int arr[], int n) {
		int first = arr[0];
		for(int i=1;i<n;i++) {
			if(arr[i]!=first) {
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
		list<int> a;
		for(int i=0;i<n;i++) {
			a.push_back(arr[i]);
		}
		vector<int> num;
		list<int> l;
		int ans = 0;
		while(!a.empty()) {
			num.push_back(a.front());
			a.pop_front();
			for(int i=0;i<num.size();i++) {
				while(!a.empty()) {
					int m = a.front();
					a.pop_front();
					if(gcd(num[i], m) == 1) {
						num.push_back(m);
					} else {
						l.push_back(m);
					}
				}
				a=l;
				l.clear();
			}
			ans++;
			num.clear();
			if(ans>=2) {
				break;
			}
		}
		if(ans==1) {
			cout<<"0\n";
			for(int i=0;i<n;i++) {
				cout<<arr[i]<<" ";
			}
			cout<<"\n";
		} else if(checkequal(arr, n)) {
			if (arr[0] == 47)
                arr[0] = 2;
            else arr[0] = 47;
            cout<<"1\n";
			for(int i=0;i<n;i++) {
				cout<<arr[i]<<" ";
			}
			cout<<"\n";
		} else {
			arr[0]=47;
			cout<<"1\n";
			for(int i=0;i<n;i++) {
				cout<<arr[i]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}
