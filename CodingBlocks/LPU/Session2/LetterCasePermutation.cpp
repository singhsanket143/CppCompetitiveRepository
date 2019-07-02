#include <iostream>
#include <vector>
using namespace std;
void helper(string str, string osf, vector<string> &v) {
        // Base case
        if(str.size() == 0) {
            v.push_back(osf);
            return;
        }
        
        // Recursion
        char ch = str[0];
        string ros = str.substr(1);
        if(ch>='a' and ch<='z') {
            helper(ros, osf+ch, v);
            helper(ros, osf+((char)(ch-32)), v);
        } else if(ch>='A' and ch<='Z') {
            helper(ros, osf+ch, v);
            helper(ros, osf+((char)(ch+32)), v);
        } else {
            helper(ros, osf+ch, v);
        }
}
    
vector<string> letterCasePermutation(string S) {
        vector<string> v;
        helper(S, "", v);
        return v;
}
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
