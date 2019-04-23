#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	n--;
	for(int i=-n;i<=n;i++) {
		for(int j=-n;j<=n;j++) {
			if(abs(i)<=abs(j) and (abs(i)+abs(j))%2==0) {
				cout<<"*";
			} else {
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
