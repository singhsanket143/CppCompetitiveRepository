#include <iostream>
#include <stack>
#define inf 1e9
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		string s;
		cin>>s;
		bool status = false;
		string *arr = new string[n];
		for(int i=0;i<n;i++) {
			string str;
			cin>>str;
			arr[i] =str;
		}
		bool equal = false;
		char c = arr[0][0];
		for(int i=1;i<n;i++){
			if(arr[i][0] == c) {
				equal = true;
			} else {
				equal = false;
				break;
			}
		}
		if(equal) {
			if(arr[0][0] == '1' and s=="Dee") {
				cout<<"Dee\n";
				continue;
			} else if(arr[0][0] == '0' and s=="Dum") {
				cout<<"Dum\n";
				continue;
			} 
		} 

		ll how_many_1=0, how_many_0=0;
		for(int i=0;i<n;i++) {
			bool b;
			string k=arr[i];
			stack<char> st;
			st.push(k[0]);
			for(int j=1;j<k.size();j++) {
				if(st.top() == k[j]) {
					continue;
				} else {
					st.push(k[j]);
				}
			}
			while(!st.empty()) {
				if(st.top() == '0') {
					how_many_0++;
				} else {
					how_many_1++;
				}
				st.pop();
			}
		}
		if(how_many_0-how_many_1 > 0) {
			cout<<"Dum\n";
		} else if(how_many_0-how_many_1<0) {
			cout<<"Dee\n";
		} else {
			cout<<s<<endl;
		}
		

	}
	return 0;
}
