#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char dest, char helper) {
	if(n==0) {
		return;
	}
	towerOfHanoi(n-1, src, helper, dest);
	cout<<"Move "<<n<<" disks from "<<src<<" to "<<dest<<" using "<<helper<<". \n";
	towerOfHanoi(n-1, helper, dest, src);
}

int main(int argc, char const *argv[])
{
	towerOfHanoi(2, 'A', 'B', 'C');
	return 0;
}
