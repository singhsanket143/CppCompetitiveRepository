#include "iostream"
#include "map"
using namespace std;

void printPalindromicSubstrings(string str) {
    map<string, string> mp;
    int maxLength = 1;
    int len = str.length(), start = 0;
    int low, high;
    string s = "";
    for(int i=0;i<str.length();i++) {
        s+=str[i];
        mp[s]=s;
        s="";
    }
    for(int i = 1; i < len; i++) {
        low = i-1;
        high = i;
        while(low >= 0 and high < len and str[low] == str[high]) {
            s = "";
            for(int i = low; i <= high; i++) {
                s+=str[i];
            }
            mp[s]=s;
            low--;
            high++;
        }
        low = i-1;
        high = i+1;
        while(low >= 0 and high < len and str[low] == str[high]) {
            s = "";
            for(int i = low; i <= high; i++) {
                s+=str[i];
            }
            mp[s]=s;
            low--;
            high++;
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++) {
        cout<<it->second<<endl;
    }
}

int main(int argc, char* argv[])
{

    printPalindromicSubstrings("geek");
    return 0;
}
