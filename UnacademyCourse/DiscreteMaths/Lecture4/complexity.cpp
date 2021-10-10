#include<iostream>

void fun(int n) {
    if(n <= 1) return;
    for(int i = 0; i < n; i++) {
        std::cout<<"*";
    }
    std::cout<<std::endl;
    fun(0.8*n);
}




int main(int argc, char const *argv[])
{
    /* code */
    fun(100);
    return 0;
}
