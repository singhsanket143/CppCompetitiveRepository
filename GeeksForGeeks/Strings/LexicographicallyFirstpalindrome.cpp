#include "iostream"
using namespace std;

void countFreq(string str, int freq[], int len) {
    for(int i=0;i<len;i++) {
        freq[str[i]-'a']++;
    }
}

bool canMakePalindrome(int freq[], int len) {
    int count_odd = 0;
    for(int i=0;i<26;i++) {
        if(freq[i]%2!=0)
            count_odd++;
    }
    if(len%2==0) {
        if(count_odd>0){
            return false;
        } else {
            return true;
        }
    }
    if(count_odd!=1){
        return false;
    }
    return true;
}

string freqOddAndRemoveItsFreq(int freq[]) {
    string odd = "";
    for(int i=0;i<26;i++) {
        if(freq[i]%2!=0) {
            freq[i]--;
            odd = odd + (char)(i+'a');
            return odd;
        }
    }
    return odd;
}

string findPalindromicString(string str) {
    int len=str.length();
    int freq[26] = {0};
    countFreq(str, freq, len);
    if(!canMakePalindrome(freq, len)) {
        return "No palindrome";
    }
    string odd = freqOddAndRemoveItsFreq(freq);
    string front="", rear="";
    for(int i=0;i<26;i++) {
        string temp="";
        if(freq[i]!=0) {
            char ch = (char)(i+'a');
            for(int j=1;j<=freq[i]/2;j++) {
                temp+=ch;
            }
            front+=temp;
            rear = temp+rear;
        }
    }
    return (front+odd+rear);
}

int main(int argc, char* argv[])
{
    string str = "malayalam";
    cout << findPalindromicString(str);

    return 0;
}
