#include "iostream"
using namespace std;

string nextGreaterBinary(string str) {
    bool status = true;
    int j=str.length()+1, k = str.length()-1;
    for(int i=str.length()-2;i>=0;i--) {
        if(str[i]=='0' and str[i+1]=='1') {
            char temp = str[i];
            str[i] = str[i+1];
            str[i+1] = temp;
            status = false;
            j=i+2;
            break;
        }
    }
    if(status == true) {
        return "No greater number";
    }
    while(j<k) {
        if(str.at(j) == '1' and str.at(k) == '0') {
            char ch = str.at(j);
            str.at(j) = str.at(k);
            str.at(k) = ch;
            j++;
            k--;
        } else if(str.at(i)=='0') {
            break;
        } else {
            j++:
        }
    }
    return str;
}

int main(int argc, char* argv[])
{

    string bnum = "10010";
    cout << "Binary representation of next greater number = "
         << nextGreaterBinary(bnum);
    return 0;
}
