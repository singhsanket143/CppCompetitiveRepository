#include "iostream"
using namespace std;

bool isSubsequence(string str1, string str2) {
    int j = 0;
    for(int i = 0; i < str2.length() and j < str1.length(); i++) {
        if(str1[j] == str2[i])
            j++;
    }
    return (j == str1.length());
}

int main(int argc, char* argv[])
{

    string s1 = "gksrek";
    string s2 = "geeksforgeeks";
    isSubsequence(s1, s2)? cout << "Yes ": cout << "No";
    return 0;
}
