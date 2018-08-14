#include "iostream"
#include "cstring"
using namespace std;
char *myStrtok(char str[], char delim) {
    static char *input = NULL;
    if (str != NULL) {
        input = str;
    }
    if(input==NULL){
        return NULL;
    }
    char *output = new char[strlen(input)+1];
    int i;
    for(i=0;input[i]!='\0';i++) {
        if(input[i]!=delim) {
            output[i]=input[i];
        } else {
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }
    }
    output[i] = '\0';
    input = NULL;
    return output;
}
int main(int argc, char* argv[])
{
    char str[] = "Hy, all welcome to coding!!";

    char *ptr;
    ptr = myStrtok(str, ' ');
    while(ptr!=NULL) {
        cout<<ptr<<endl;
        ptr = myStrtok(NULL, ' ');
    }

    return 0;
}
