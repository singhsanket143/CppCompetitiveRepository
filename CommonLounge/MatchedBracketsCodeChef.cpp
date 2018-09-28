#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	long long n;
	cin>>n;
	long long arr[n];
	for(long long i=0;i<n;i++) {
		cin>>arr[i];
	}
	int start=1, max_current = 0, length=0, max_length=0, max_position=0, max_length_position=0;
	int temp, current = 0;
	for(long long i=0;i<n;i++) {
		temp = arr[i];
		if(temp == 1) {
			current++;
			length++;
			if(current > max_current) {
				max_current = current;
				max_position = i+1;
			}
		} else {
			current--;
			length++;
			if(current==0) {
				if(length > max_length) {
					max_length = length;
					max_length_position = start;
				}
				length = 0;
				start = i+2;
			}
		}
	}
	cout << max_current << " " << max_position << " " << max_length << " " << max_length_position << endl;
}
