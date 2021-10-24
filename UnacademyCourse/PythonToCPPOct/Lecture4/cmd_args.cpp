#include<iostream>

int main(int argc, char const *argv[])
{
    /* code */
    std::cout<<argc<<"\n"; // no of parameters
    for(int i = 0; i < argc; i++) 
        std::cout<<argv[i]<<" ";
    return 0;
}
