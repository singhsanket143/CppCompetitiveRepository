#include<bits/stdc++.h>
using namespace std;
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

class Test {
public:
	int x;
	mutable string LOG; // info error warn

	int getX() const {
		cout<<"with const"<<endl;
		LOG = "test";
		return x;
	}

	int getX() {
		std::cout<<("without const");
		return x;
	}

	void setX(int x) {
		this->x = x;
	}
};

// outside class
void fun(const Test& t) {
	cout<<t.getX()<<endl;
	//t.setX(10);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	const int MAX_VAL = 1000;
	cout<<MAX_VAL<<endl;
	// MAX_VAL = 99; // this gives error 
	// MAX_VAL++;  // this gives error 
	// MAX_VAL += 1; // this gives error 
	// MAX_VAL = MAX_VAL + 1; // this gives error 

	// int *p = &MAX_VAL;

	const int *p = &MAX_VAL;
	int *ptr = new int;
	ptr = (int *)&MAX_VAL;
	*ptr = 10;
	cout<<ptr<<" "<<p<<endl;
	cout<<*ptr<<" "<<*p<<endl;
	cout<<MAX_VAL<<endl;
	cout<<&MAX_VAL<<endl;

	cout<<"***********"<<endl;

	int* const a = new int; // with this we wont be able to reassign a new bucket but we can change the value of bucket
	
	*a = 2;
	cout<<*a<<endl;
	// a = (int *)&MAX_VAL;

	const int *p2; // with this we can't change the content but can reassign
	int const *p1; // with this we can't change the content but can reassign


	const int* const z = &MAX_VAL; // neither update not assign

	Test t;
	fun(t);

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
