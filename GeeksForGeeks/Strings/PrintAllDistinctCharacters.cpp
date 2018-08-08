#include "iostream"
#include "algorithm"
using namespace std;

void distinctCharacters(string str) {
    int freqmap[256] = {0};
    int index[256] = {0};
    for(int i=0;i<256;i++) {
        index[i]=str.length()+1;
    }
    for(int i=0;i<str.length();i++) {
        if(freqmap[str[i]] == 0) {
            freqmap[str[i]]++;
            index[str[i]] = i;
        } else {
            freqmap[str[i]]++;
            index[str[i]] = str.length()+1;
        }
    }
    sort(index, index+256);
    for(int i=0;i<256;i++) {
        if(index[i]==str.length()+1 or str[index[i]]==' '){
            continue;
        } else {
            cout<<str[index[i]];
        }
    }
}

int main(int argc, char* argv[])
{
    string str = "Hello geeks";
    distinctCharacters(str);
    return 0;
}
