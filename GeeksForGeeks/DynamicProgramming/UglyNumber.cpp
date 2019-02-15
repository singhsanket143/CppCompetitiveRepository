#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int next_multiple_of_2 = 2, next_multiple_of_3=3, next_multiple_of_5=5, i2=0, i3=0, i5=0;
	long long int ugly[n];
	ugly[0]=1;
	int next_ugly;
	for(int i=1;i<n;i++) {
		next_ugly = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
		ugly[i] = next_ugly;
		if(next_ugly==next_multiple_of_2) {
			i2+=1;
			next_multiple_of_2 = ugly[i2]*2;
		}
		if(next_ugly==next_multiple_of_3) {
			i3+=1;
			next_multiple_of_3 = ugly[i3]*3;
		}
		if(next_ugly==next_multiple_of_5) {
			i5+=1;
			next_multiple_of_5 = ugly[i5]*5;
		}
	}
	for(int i=1;i<n;i++) {
		cout<<ugly[i]<<" ";
	}
	return 0;
}
