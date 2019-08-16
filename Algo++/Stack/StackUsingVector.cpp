#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Stack {
private:
	vector<T> v;
public:
	void push(T data) {
		v.push_back(data);
	}

	bool empty() {
		return v.size() == 0;
	}

	void pop() {
		if(not empty()) {
			v.pop_back();
			return;
		}
		cout<<"Stack Already Empty";
		return;
	}
	T top() {
		if(!empty()) {
			return v[v.size()-1];
		}
		cout<<"Stack Is Empty";
		return -1;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
