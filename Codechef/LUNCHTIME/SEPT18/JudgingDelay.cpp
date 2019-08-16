#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	
	while(t--) {
		int n;
		cin>>n;
		int count = 0;
		while(n--) {
			int a,b;
			cin>>a>>b;
			if(abs(a-b)>5) {
				count++;
			}	
		}
		cout<<count<<endl;
	}
	
	return 0;
}
