#include <iostream>
using namespace std;
void dnf(int *arr, int n) {
	int st = 0, end = n-1, mid=0;

	while(mid<=end) {
		if(arr[mid]==1) mid++;
		else if(arr[mid]==2) {
			swap(arr[mid], arr[end]);
			end--;
		} else {
			swap(arr[mid], arr[st]);
			st++;
			mid++;
		}
	}
}
int main(int argc, char const *argv[])
{

	return 0;
}
