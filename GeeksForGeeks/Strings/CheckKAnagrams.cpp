#include "iostream"
using namespace std;

bool kAnagrams(string str1, string str2, int k) {
    int freq[26] = {0};
    int count = 0;
    for(int i = 0; i < str1.length(); i++) {
        freq[str1[i]-'a']++;
    }
    for(int i = 0; i < str2.length(); i++) {
        if(freq[str2[i]-'a'] > 0) {
            freq[str2[i]-'a']--;
        } else {
            count++;
        }
    }
    return count <= k;
}

int main(int argc, char* argv[])
{

    string str1 = "fodr";
    string str2 = "gork";
    int k = 2;
    if (kAnagrams(str1, str2, k) == true)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
