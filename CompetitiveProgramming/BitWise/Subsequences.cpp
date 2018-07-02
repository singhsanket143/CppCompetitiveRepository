#include "iostream"
#include "string"
using namespace std;

void filterString(std::string str, int n) {
    int i = 0;
    while(n) {
        (n&1)?(std::cout<<str[i]):(std::cout<<"");
        i++;
        n >>= 1;
    }
    std::cout<<"\n";
}

void generateSubsequences(std::string str) {
    int n = str.length();
    int range = (1<<n) - 1;

    for(int i = 0 ; i <= range ; i++) {
        filterString(str, i);
    }
}

int main(int argc, char* argv[])
{

    std::string str;
    std::cin>>str;
    generateSubsequences(str);
    return 0;
}
