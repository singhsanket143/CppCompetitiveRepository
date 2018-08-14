#include "iostream"
using namespace std;

int countSubsequences(string s) {
    int aCount = 0, bCount = 0, cCount = 0;
    for(unsigned int i = 0;i<s.size(); i++) {
        if(s[i]=='a') {
            aCount = (1 + 2*aCount);
        } else if(s[i]=='b') {
            bCount = (aCount + 2*bCount);
        } else {
            cCount = (bCount + 2*cCount);
        }
    }
    return cCount;
}

int main(int argc, char* argv[])
{
    string s = "abbc";
    cout << countSubsequences(s) << endl;

    return 0;
}
