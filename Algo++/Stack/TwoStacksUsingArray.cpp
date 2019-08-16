#include <iostream>
using namespace std;

class twoStacks {
	int *arr;
	int size;
	int top1;
	int top2;

public:
	twoStacks(int n) {
		size = n;
		arr = new int[n];
		top1 = -1;
		top2 = size;
	}

	void push1(int x) {
		if(top1 < top2-1) {
			top1++;
			arr[top1] = x;
		} else {
			cout<<"Stack Overflow";
			exit(1);
		}
	}
	void push2(int x) {
		if(top1 < top2-1) {
			top2--;
			arr[top2] = x;
		} else {
			cout<<"Stack Overflow";
			exit(1);
		}
	}
	int pop1() {
		if(top1 >=0) {
			int data = arr[top1];
			top1--;
			return data;
		} else {
			cout<<"Stack Overflow";
			exit(1);
		}
	}
	int pop2() {
		if(top2<size) {
			int data = arr[top2];
			top2++;
			return data;
		} else {
			cout<<"Stack Overflow";
			exit(1);
		}
	}

};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
