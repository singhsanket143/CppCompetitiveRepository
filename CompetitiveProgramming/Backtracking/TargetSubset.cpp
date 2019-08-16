#include <iostream>
using namespace std;

void targetSubset(int *arr, int n, int si, int target, string osf) {
	if(si == n) {
		if(target == 0) {
			cout<< "{" << osf << "}\n";
		}
		return;
	}
	targetSubset(arr, n, si+1, target - arr[si], osf + to_string(arr[si]) + ", ");
	targetSubset(arr, n, si+1, target, osf);
}

int main(int argc, char const *argv[])
{
	/* code */
	int arr[5] = {1,2,3,4,5};
	targetSubset(arr, 5, 0, 5, "");
	return 0;
}
