#include "iostream"
using namespace std;

int pattern(string str) {
    char last = st[0];
    int i =1, counter = 0;
    while(i < str.size()) {
        if(str[i] == '0' and last == '1') {
            while(str[i] == '0') {
                i++;
            }
            if(str[i] == '1') {
                counter++;
            }
        }
        last = str[i];
        i++;
    }
    return counter;
}

int main(int argc, char* argv[])
{

    string str = "1001ab010abc01001";
    cout << pattern(str) << endl;
    return 0;
}
