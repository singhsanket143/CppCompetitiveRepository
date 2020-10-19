#include<iostream>
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

void subsequence(string str, string osf) {
	if(str.size() == 0) {
		// base case
		cout<<osf<<endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1); // rest of the string
	subsequence(ros, osf+ch);
	subsequence(ros, osf);
}

void codesOfString(string str, string osf, char *mapping) {
	// Base case
	if(str.size() == 0) {
		cout<<osf<<endl;
		return;
	}
	int firstNumber = str[0] - '0';
	int secondNumber;
	if(str.size() >= 2) {
		// when size of string passed is greater than or equal to 2
		secondNumber = stoi(str.substr(0, 2));
		if(secondNumber <= 26) {
			// call allowed
			codesOfString(str.substr(2), osf+mapping[secondNumber], mapping);
		}
		codesOfString(str.substr(1), osf+mapping[firstNumber], mapping);
	} else {
		// when size of string passed if equal to 1
		codesOfString(str.substr(1), osf+mapping[firstNumber], mapping);
	}

}


int countNoConsecutive1(int n) {
	// Base case 
	if(n == 1) return 2;
	if(n == 2) return 3;
	// Recursive task
	int cand1 = countNoConsecutive1(n-1);
	int cand2 = countNoConsecutive1(n-2);

	// self work
	return cand1 + cand2;
}

// f(n) -> nth fibonacci
int fibonacci(int n) {
	// Base case 
	if(n == 0 or n == 1) return n;
	// Recursive task
	int cand1 = fibonacci(n-1);
	int cand2 = fibonacci(n-2);

	// self work
	return cand1 + cand2;
}

int main(int argc, char const *argv[])
{
	file_i_o();
	// int n;
	// cin>>n; // user input
	// cout<<fibonacci(n);
	// char mapping[27] = {'#', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm','n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	// string str;
	// cin>>str;
	// codesOfString(str, "", mapping);
	string str;
	cin>>str;
	subsequence(str, "");
	return 0;
}