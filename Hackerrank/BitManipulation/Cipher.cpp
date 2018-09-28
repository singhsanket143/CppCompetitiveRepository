#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int z=0;
    string result = "";
    while(s[z]!='1') {
        result+="0";
        z++;
    }
    
    result+="1";
    int bit1 = 1;
    for(int i=z+1;i<k;i++) {
        int bit2 = s[i]-'0';
        int r = bit1^bit2;
        result+=to_string(r);
        bit1^=r;
    }
    for(int i=k;i<n;i++) {
        int bit2 = result[i-k]-'0';
        bit1^=bit2;
        int bit3 = s[i] - '0';
        int r = bit1^bit3;
        result+=to_string(r);
        bit1=bit1^r;
    }
    cout<<result.substr(0, n);
    return 0;
}
