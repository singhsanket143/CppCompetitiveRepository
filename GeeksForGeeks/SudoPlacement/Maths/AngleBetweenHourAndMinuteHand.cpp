#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		double h, m;
		cin>>h>>m;
		double hour = 30*h;
		double min = 6*m;
		double c=m/2; // Factor on hour hand by minutes hand
		hour+=c;
		double angle = abs(hour-min);
		cout<<std::min((int)angle, (int)(360-angle))<<endl;;
	}
	return 0;
}
