#include "iostream"
#include "cstring"
using namespace std;
int main(int argc, char* argv[])
{
    char str[] = "Hy, all welcome to coding!!";

    char *ptr;
    ptr = strtok(str, " ");
    while(ptr!=NULL) {
        cout<<ptr<<endl;
        ptr = strtok(NULL, " ");
    }

    return 0;
}
