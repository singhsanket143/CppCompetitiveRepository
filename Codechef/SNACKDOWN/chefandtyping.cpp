#include <iostream>
#include <map>
#define ll long long int
using namespace std;

double calcTime(string str) {
	double ans = 0.2;
	for(int i=1;i<str.size();i++) {
		if((str[i] == 'd' or str[i] == 'f') and (str[i-1] == 'j' or str[i-1] == 'k')) {
			ans+=0.2;
		} else if ((str[i] == 'd' or str[i] == 'f') and (str[i-1] == 'd' or str[i-1] == 'f')) {
			ans+=0.4;
		} else if((str[i] == 'j' or str[i] == 'k') and (str[i-1] == 'd' or str[i-1] == 'f')) {
			ans+=0.2;
		} else if((str[i] == 'j' or str[i] == 'k') and (str[i-1] == 'j' or str[i-1] == 'k')) {
			ans+=0.4;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		double ans = 0.0;
		std::map<string, double> mp;
		std::map<string,double>::iterator it;
		while(n--) {
			string str;
			cin>>str;
			double result= calcTime(str);
			it = mp.find(str);
			if(it != mp.end()) {
				ans+=mp.find(str)->second/2;
			} else {
				ans+=result;
				mp[str] = result;
			}
		}
		cout<<ans*10<<endl;
	}
	return 0;
}
