#include "iostream"
using namespace std;

char kthCharacter(string str, int k) {
    string expand = "";
    string temp;
    int freq = 0;
    for(int i=0;str[i]!='\0';) {
        temp = "";
        freq = 0;
        while(str[i]>='a' and str[i]<='z') {
            temp+=str[i];
            i++;
        }
        while(str[i]>='1' and str[i]<='9') {
            freq = freq*10 + str[i]-'0';
            i++;
        }
        for(int j=1;j<=freq;j++) {
            expand.append(temp);
        }
    }
    if(freq==0) {
        expand.append(temp);
    }
    return expand[k-1];
}

int main(int argc, char* argv[])
{

    string str = "ab4c12ed3";
    int k = 21;
    cout << kthCharacter(str, k) << endl;
    return 0;
}
