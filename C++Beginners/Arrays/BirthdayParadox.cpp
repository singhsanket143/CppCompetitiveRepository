#include <iostream>
using namespace std;

int main() {
	float p;
	cin>>p;
	if(p==1){
		cout<<"366";
	}
	int num = 365;
	float denom = 365.0;
	float prob = 1.0;  // Probability of different birthday
	int count = 0;

	while(prob > 1 - p) {
		prob*=(num/denom);
		num--;
		count++;
	}
	cout<<count;
	return 0;
}
