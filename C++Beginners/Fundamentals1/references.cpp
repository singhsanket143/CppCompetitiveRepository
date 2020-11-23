#include <iostream>
#include <algorithm>
using namespace std;

void swapbyadd(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
	return;
}

void swapbyref(int &x, int& y) {
	int temp = x;
	x = y;
	y = temp;
	return;
}

void swapbycopy(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
	return;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int x = 10;
	int y = 20;
	cout<<x<<" "<<y<<endl;
	swapbycopy(x, y);
	cout<<x<<" "<<y<<endl;
	swapbyref(x, y);
	cout<<x<<" "<<y<<endl;
	swapbyadd(&x, &y);
	cout<<x<<" "<<y<<endl;

	return 0;
}