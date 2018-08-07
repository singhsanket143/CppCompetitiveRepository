#include "iostream"
#include "cstring"
using namespace std;

void rotate(char a[], int k) {
    int l = strlen(a);
    while(l >= 0) {
        a[l+k] = a[l];
        l--;
    }
    int start = 0;
    l = strlen(a);
    while(start < k) {
        a[start] = a[l-k];
        start++;
        l++;
    }
    l = strlen(a);
    a[l-k] = '\0';

}

int main(int argc, char* argv[])
{
    char a[100] = "Coding Kids";
    int k = 2;
    rotate(a, k);
    cout<<a<<endl;

    return 0;
}
