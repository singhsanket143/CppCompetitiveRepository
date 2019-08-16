#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int m, n; // m denotes rows and n denotes column
	cin>>m>>n;
	char arr[m][n];
	// cin.get();
	for(int row=0;row<m;row++) {
		cin.getline(arr[row], n);
	}
	for(int row=0;row<m;row++) {
		cout<<arr[row]<<"\n";
	}

	return 0;
}
