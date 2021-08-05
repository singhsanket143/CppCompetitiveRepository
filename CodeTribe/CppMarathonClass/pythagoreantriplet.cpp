#include<iostream>

int main() {
    long long int a;
    std::cin>>a;
    long long int x = a*a;
    if((a % 2) == 0) {
        std::cout<<(((x)/4)-1)<<" "<<a<<" "<<(((x)/4)+1)<<"\n";
    } else {
        std::cout<<a<<" "<<(x - 1)/2<<" "<<(x + 1)/2<<"\n";
    }


    return 0;
}