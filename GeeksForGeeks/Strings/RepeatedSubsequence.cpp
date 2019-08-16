#include "iostream"
using namespace std;

bool isPalindrome(string str) {
    int lo = 0, hi = str.length() - 1;
    while(lo<=hi) {
        if(str[lo] != str[hi]) {
            return false;
        }
        lo++;
        hi--;
    }
    return true;
}

bool repeatedSubsequence(string str) {
    int n = str.length() - 1;
    int freq[256] = {0};
    for(int i = 0; i < n; i++) {
        freq[str[i]]++;
        if(freq[str[i]] > 3) {
            return true;
        }
    }
    int k = 0;
    for(int i=0;i<n;i++) {
        if(freq[str[i]] > 1) {
            str[k++] = str[i];
        }
    }
    str[k] = '\0';
    if(isPalindrome(str)) {
        if(k&1) {
            return str[k/2] == str[k/2 - 1];
        }
        return false;
    }
    return true;
}

int main(int argc, char* argv[])
{

    string str = "abcabd";
    cout<<repeatedSubsequence(str);
    return 0;
}
