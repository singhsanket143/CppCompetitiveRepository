#include<iostream>
using namespace std;
int main() {
	bool b = true; // true / false
	int i = 10; 
	short s = 34;
	long l = 23L;
	short int si = 12;
	long long ll = 23;
	long long int lli = 45;
	cout<<sizeof(i)<<" "<<sizeof(s)<<" "<<sizeof(l)<<" "<<sizeof(b)<<" "<<sizeof(si)<<" "<<sizeof(ll)<<" "<<sizeof(lli)<<endl;

	float f = 3.14f;
	double d = 3.14;
	cout<<sizeof(f)<<" "<<sizeof(d)<<endl;

	char ch = 'a';
	string str = "sanket singh"; // string object
	char sa[] = "unacademycodechef"; // character array

	cout<<str<<endl;
	cout<<sa<<endl;
	cout<<sizeof(ch)<<" "<<sizeof(str)<<" "<<sizeof(sa)<<endl;

	unsigned int ui = -2;
	int x = ui;
	cout<<ui<<" "<<x<<" "<<sizeof(ui)<<endl;

	cout<<INT_MAX<<endl;
	return 0;
}