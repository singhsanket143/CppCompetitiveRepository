#include<iostream>

int main(int argc, char const *argv[])
{
    int arr[3] = {1,2,3};
    std::cout<<*arr<<"\n";
    std::cout<<*(arr+1)<<"\n";
    std::cout<<*(arr+2)<<"\n"; // arr[2]
    return 0;
}
