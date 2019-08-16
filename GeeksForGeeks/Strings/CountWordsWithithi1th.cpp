#include "iostream"
using namespace std;

int count(string str, int len) {
    int count = 1;
    if(len==1) {
        return count;
    }
    if(str[0]==str[1]){
        count*=1;
    } else {
        count*=2;
    }
    for(int i=1;i<len-1;i++) {
        if(str[i] == str[i-1] == str[i+1]) {
            count*=1;
        } else if(str[i] == str[i-1] or str[i] == str[i+1] or str[i+1] == str[i-1]) {
            count*=2;
        } else {
            count*=3;
        }
    }
    if(str[len-1]==str[len-2]){
        count*=1;
    } else {
        count*=2;
    }
    return count;
}

int main(int argc, char* argv[])
{

    cout<<count("abc", 3)<<endl;
    return 0;
}
