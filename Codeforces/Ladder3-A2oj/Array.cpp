#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, x;
	cin>>n;
	std::vector<int> neg, pos, zero;
	for(int i=0;i<n;i++) {
		cin>>x;
		if(x==0) zero.push_back(x);
		else if (x<0) neg.push_back(x);
		else pos.push_back(x);
	}
	if(neg.size()%2==0) {
		zero.push_back(neg.back());
		neg.pop_back();
	}
	if(pos.size()==0) {
		pos.push_back(neg.back());
		neg.pop_back();
		pos.push_back(neg.back());
		neg.pop_back();
	}
	cout<< neg.size()<<" ";
	for(int i=0;i<neg.size();i++) {
		cout<<neg[i]<<" ";
	}
	cout<<"\n"<<pos.size()<<" ";
	for(int i=0;i<pos.size();i++) {
		cout<<pos[i]<<" ";
	}
	cout<<"\n"<<zero.size()<<" ";
	for(int i=0;i<zero.size();i++) {
		cout<<zero[i]<<" ";
	}
	return 0;
}
