#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	stack<string> s;
	s.push("Mango");
	s.push("Apple");
	s.push("Grapes");
	while(!s.empty()) {
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}