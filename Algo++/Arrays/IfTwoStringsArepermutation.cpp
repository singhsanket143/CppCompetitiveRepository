#include "iostream"
#include "cstring"
using namespace std;

bool isPermutation(char *s1, char *s2) {
    if (strlen(s1) != strlen(s2)) {
        return false;
    }
    int freq[26] = {0};
    for(int i=0;i<strlen(s1);i++) {
        freq[s1[i] - 'a']++;
    }
    for(int i=0;i<strlen(s2);i++) {
        freq[s2[i] - 'a']--;
    }
    for(int i=0;i<strlen(s2);i++) {
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    char s1[100], s2[100];
    cin>>s1;
    cin>>s2;
    cout<<isPermutation(s1, s2);
    return 0;
}
