#include <iostream>
#include <stack>
using namespace std;

bool balanced(string str){
	stack<char> st;
	for (int i = 0; i < str.size(); i++)
	{
		if(str[i] == '('){
			st.push('(');
		}
		else{
			if(str[i] == ')'){
				if(st.empty()){
					return false;
				}
				st.pop();
			}
		}	
	}
	return st.empty();
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	if(balanced(str)){
		cout<<str<<" is balanced"<<endl;
	}
	else{
		cout<<str<<" is not balanced"<<endl;
	}
}




