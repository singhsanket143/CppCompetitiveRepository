#include "iostream"
#include "vector"
#include "map"
using namespace std;

int countAnagramSubstring(string str) {
    int n = str.length();
    map< vector<int>, int> mp;
    for(int i=0;i<n;i++) {
        vector<int> freq(26, 0);
        for(int j=i;j<n;j++) {
            freq[str[j]-'a']++;
            mp[freq]++;
        }
    }
    int result = 0;
    for(auto it=mp.begin();it!=mp.end();it++) {
        int freq = it->second;
        result += (freq*(freq-1))/2;
    }
    return result;
}

int main(int argc, char* argv[])
{

    string str = "xyyx";
    cout << countAnagramSubstring(str) << endl;
    return 0;
}
