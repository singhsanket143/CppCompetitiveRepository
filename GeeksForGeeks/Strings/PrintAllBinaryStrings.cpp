#include "iostream"
using namespace std;

void printcomb(string str, int index) {
    if(index == str.length()) {
        cout<<str<<endl;
        return;
    }
    if(str[index] == '?') {
        str[index] = '0';
        printcomb(str, index+1);
        str[index] = '1';
        printcomb(str, index+1);
    } else {
        printcomb(str, index+1);
    }
    return;
}

int main(int argc, char* argv[])
{

    printcomb("1??0?101", 0);
    return 0;
}
