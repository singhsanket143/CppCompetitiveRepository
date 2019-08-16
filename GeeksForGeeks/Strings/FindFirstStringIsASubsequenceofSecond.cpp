/*
Given two strings str1 and str2, find if str1 is a 
subsequence of str2. A subsequence is a sequence that can 
be derived from another sequence by deleting some elements 
without changing the order of the remaining elements (source: wiki). 
Expected time complexity is linear.
*/

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
