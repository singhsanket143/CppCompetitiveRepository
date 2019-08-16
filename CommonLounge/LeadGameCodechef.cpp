#include<bits/stdc++.h>
using namespace std;
int main() {
	int t, win, gameWin, maxLead=INT_MIN, Lead, a=0, b=0;
	cin>>t;
	while(t--) {
		int x, y;
		cin>>x>>y;
		a+=x;
		b+=y;
		if(a>b){
			win=1;
			Lead = a-b;
		} else {
			win=2;
			Lead = b-a;
		}
		
		if(Lead>maxLead){
			maxLead = Lead;
			gameWin = win;
		}
	}
	cout<<gameWin<<" "<<maxLead;
	return 0;
}