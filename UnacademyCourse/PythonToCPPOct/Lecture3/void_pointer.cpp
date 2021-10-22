#include<iostream>
int main(int argc, char const *argv[])
{
    int x = 10;
    char ch = 'a';
    void* ptr = &x;
    ptr = &ch;
    return 0;
}
