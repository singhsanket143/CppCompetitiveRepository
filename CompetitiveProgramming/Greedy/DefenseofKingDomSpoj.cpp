#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int w, h, x;
		cin>>w>>h>>x;
		if(x==0) {
			cout<<w*h<<endl;
			continue;
		}
		int xaxis[x];
		int yaxis[x];
		for(int i=0;i<x;i++) {
			cin>>xaxis[i];
			cin>>yaxis[i];
		}
		sort(xaxis, xaxis+x);
		sort(yaxis, yaxis+x);
		int dx = xaxis[0], dy = yaxis[0];
		for(int i=1;i<x;i++) {
			dx = max(dx, xaxis[i] - xaxis[i-1]);
			dy = max(dy, yaxis[i] - yaxis[i-1]);
		}
		dx = max(dx, w+1 - xaxis[x-1]);
		dy = max(dy, h+1 - yaxis[x-1]);
		cout<<((dx-1)*(dy-1))<<endl;;
	}
	return 0;
}
