#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	// 2d array initialisation
	int arr[3][2];
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			cin>>arr[i][j];
		}
	}
	// Printing a 2d array
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			cout<<arr[i][j]<<", ";
		}
		cout<<"\n";
	}
	return 0;
}
