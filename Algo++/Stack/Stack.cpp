#include <iostream>
#include <stack>
using namespace std;

bool balacedParenthesis(string str) {
	stack<char> s;
	for(int i = 0; i < str.length(); i++) {
		char curr = str[i];
		if(curr == '(') {
			s.push(curr);
		} else if(curr == ')') {
			if(s.empty() or s.top() == '(') {
				return false;
			}
			s.pop();
		}
	}
	return s.empty();
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	if(balacedParenthesis(str)) {
		cout<<"Yes"; 
	} else {
		cout<<"No";
	}
	
	return 0;
}
