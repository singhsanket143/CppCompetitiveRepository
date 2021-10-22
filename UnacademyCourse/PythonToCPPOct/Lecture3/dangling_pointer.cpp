#include<iostream>

int main(int argc, char const *argv[])
{
    int *ptr; // wild pointer
    {
        int x = 10;
        ptr = &x;
    }

    std::cout<<ptr<<"\n"; // dangling pointer
    return 0;
}
