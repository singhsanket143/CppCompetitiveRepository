#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
	stack<string> st;
	st.push("abc");
	st.push("def");
	cout<<st.top()<<endl;
	st.pop();
	st.pop();
	st.pop();
	
	cout<<st.empty()<<endl;

	return 0;
} 