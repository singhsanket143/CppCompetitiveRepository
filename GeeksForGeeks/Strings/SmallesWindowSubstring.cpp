#include "iostream"
#include "limits"
using namespace std;

string findSubstring(string str, string pat) {
    int len1 = str.length();
    int len2 = pat.length();
    if(len1 < len2) {
        cout << "No such window exist!!";
        return "-1";
    }
    int hash_pat[256] = {0};
    int hash_str[256] = {0};
    for(int i = 0; i < pat.length(); i++) {
        hash_pat[pat[i]]++;
    }
    int start = 0, start_index = -1, min_len = INT_MAX, count = 0;
    for(int i = 0; i < len1; i++) {
        hash_str[str[i]]++;
        if(hash_pat[str[i]] != 0 and hash_str[str[i]] <= hash_pat[str[i]]) {
            count++;
        }
        if(count == len2) {
            while(hash_str[str[start]] > hash_pat[str[start]] or hash_pat[str[start]] == 0) {
                if(hash_str[str[start]] > hash_pat[str[start]]) {
                    hash_str[str[start]]--;
                }
                start++;
            }
            int len_window = i - start + 1;
            if(min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }
    if(start_index == -1) {
        cout << "No such window exist!!";
        return "-1";
    }
    return str.substr(start_index, min_len);
}

int main(int argc, char* argv[])
{

    string str = "this is a test string";
    string pat = "tist";

    cout << "Smallest window is : \n" << findSubstring(str, pat);
    return 0;
}
