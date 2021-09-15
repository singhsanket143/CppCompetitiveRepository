#include<iostream>

void gun() {
    std::cout<<"OOOO this is a gun\n";
}

void fun() {
    gun();
    std::cout<<"Hey this was fun\n";
}

int main(int argc, char const *argv[])
{
    int x = 10; // this creates x in call stack frame
    fun();
    std::cout<<x<<"\n";
    return 0;
}
