#include "iostream"
using namespace std;

int longestPalSubstring(string str) {
    int maxLength = 1;
    int len = str.length(), start = 0;
    int low, high;
    for(int i = 1; i < len; i++) {
        low = i-1;
        high = i;
        while(low >= 0 and high < len and str[low] == str[high]) {
            if(high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
            low--;
            high++;
        }
        low = i-1;
        high = i+1;
        while(low >= 0 and high < len and str[low] == str[high]) {
            if(high - low + 1 > maxLength) {
                start = low;
                maxLength = high - low + 1;
            }
            low--;
            high++;
        }
    }
    cout << "Longest Palindrome Substring is: ";
    for(int i = start; i <= start + maxLength - 1; i++) {
        cout<<str[i];
    }
    return maxLength;
}

int main(int argc, char* argv[])
{

    string str = "forgeeksskeegfor";
    cout << longestPalSubstring(str)<<endl;
    return 0;
}
