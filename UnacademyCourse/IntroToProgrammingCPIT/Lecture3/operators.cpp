#include<iostream>

int main() {
    int a = 10;
    int b = 3;

    // arithmetic 
    std::cout<<a + b<<"\n";
    std::cout<<a - b<<"\n";
    std::cout<<a * b<<"\n";
    std::cout<<a / b<<"\n";
    std::cout<<a % b<<"\n";

    // comparison operator
    std::cout<<(a > b)<<"\n";
    std::cout<<(a >= b)<<"\n";
    std::cout<<(a < b)<<"\n";
    std::cout<<(a <= b)<<"\n";
    std::cout<<(a == b)<<"\n";
    std::cout<<(a != b)<<"\n";

    // logical operators
    std::cout<<((10 > 2) and (7 < 5))<<"\n";
    std::cout<<((10 > 2) && (7 < 5))<<"\n";
    std::cout<<((10 > 2) or (7 < 5))<<"\n";
    std::cout<<((10 > 2) || (7 < 5))<<"\n";
    std::cout<<!((10 > 2) and (7 < 5))<<"\n";
    std::cout<<not ((10 > 2) and (7 < 5))<<"\n";

    // bitwise operator
    std::cout<<(a & b)<<"\n";
    std::cout<<(a | b)<<"\n";
    std::cout<<(a ^ b)<<"\n";
    std::cout<<~a<<"\n";
    std::cout<<(5 << 1)<<"\n";
    std::cout<<(5 >> 1)<<"\n";


    int x = ++a;
    std::cout<<x<<" "<<a<<"\n";

    int y = a++;
    std::cout<<y<<" "<<a<<"\n";
    return 0;
}