#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int c1,c2,c3,c4,n,m;
	while(t--) {
		cin>>c1>>c2>>c3>>c4;
		cin>>n>>m;
		int rickshaw[n];
		int cab[m];
		for(int i=0;i<n;i++) {
			cin>>rickshaw[i];
		}
		for(int i=0;i<m;i++) {
			cin>>cab[i];
		}
		int rickeshawCost = 0;
		for(int i=0;i<n;i++) {
			rickeshawCost += min(c1*rickshaw[i], c2);
		}
		rickeshawCost = min(rickeshawCost, c3);
		int cabCost = 0;
		for(int i=0;i<m;i++) {
			cabCost += min(c1*cab[i], c2);
		}
		cabCost = min(cabCost, c3);
		int finalResult = min(c4, cabCost+rickeshawCost);
		cout<<finalResult<<endl;
	}
	return 0;
}
