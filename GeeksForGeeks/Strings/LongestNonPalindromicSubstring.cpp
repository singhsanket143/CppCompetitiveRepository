#include "iostream"
using namespace std;

bool isPalindrome(string str) {
    int low= 0, high = str.length()-1;
    while(low<=high) {
        if(str[low]!=str[high]) {
            return false;
        }
        low++;
        high--;
    }
    return true;
}

int maxLenNonPalindrome(string str) {
    char ch=str[0];
    int i=1;
    for(i=1;i<str.length();i++) {
        if(str[i]!=ch) {
            break;
        }
    }
    if(i==str.length()) {
        return 0;
    }
    if(isPalindrome(str)){
        return str.length()-1;
    }
    return str.length();
}

int main(int argc, char* argv[])
{
    string str = "abba";
    cout << "Maximum length = "
         << maxLenNonPalindrome(str);

    return 0;
}
