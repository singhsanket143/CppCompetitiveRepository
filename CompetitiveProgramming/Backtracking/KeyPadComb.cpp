#include <iostream>
using namespace std;

string getCode(char ch) {
		if (ch == '2')
			return "abc";
		else if (ch == '3')
			return "def";
		else if (ch == '4')
			return "ghi";
		else if (ch == '5')
			return "jkl";
		else if (ch == '6')
			return "mno";
		else if (ch == '7')
			return "pqrs";
		else if (ch == '8')
			return "tuv";
		else if (ch == '9')
			return "wxyz";
		else if (ch == '0')
			return ".;";
		else
			return "";
}

void printKP(string ques, string ans) {
		if (ques.length() == 0) {
			cout<<(ans)<<endl;
			return;
		}

		char ch = ques[0];
		string ros = ques.substr(1);
		string code = getCode(ch);

		for (int i = 0; i < code.length(); i++) {
			printKP(ros, ans + code[i]);
		}
}



int main(int argc, char const *argv[])
{
	printKP("23", "");
	return 0;
}
