#include "iostream"

int main() {
    int x = 34, y = 20;

    // arithmetic operator
    std::cout<<(x + y)<<"\n"; // addition
    std::cout<<(x - y)<<"\n"; // substraction
    std::cout<<(x * y)<<"\n"; // multiplication
    std::cout<<(x / y)<<"\n"; // division - floor division
    std::cout<<(x % y)<<"\n"; // remainder calculate
    std::cout<<(++x)<<"\n"; // prefix operator
    std::cout<<(x++)<<"\n"; // postfix operator

    // Relational Operator
    std::cout<<(x < y)<<"\n";
    std::cout<<(x <= y)<<"\n";
    std::cout<<(x == y)<<"\n";
    std::cout<<(x > y)<<"\n";
    std::cout<<(x >= y)<<"\n";
    std::cout<<(x != y)<<"\n";

    std::cout<<"---\n";
    // logical operator
    std::cout<<((34 < 54) && (1 < 2))<<"\n";
    std::cout<<((34 < 54) and (1 < 2))<<"\n";
    std::cout<<((34 < 54) || (1 < 2))<<"\n";
    std::cout<<((34 < 54) or (1 < 2))<<"\n";
    std::cout<<(!(34 < 54))<<"\n";
    std::cout<<(not (34 < 54))<<"\n";

    // Assignment operator
    int x1 = 10; 
    std::cout<<x1<<"\n";
    x1 = x1 + 2;
    std::cout<<x1<<"\n";
    x += 2; // x = x + 2
    x -= 5; // x = x - 5
    x *= 2; // x = x * 2
    x /= 3; // x = x / 3
    x %= 4; // x = x % 4


    // bitwise operator
    std::cout<<(8 & 9)<<"\n";
    std::cout<<(8 | 9)<<"\n";
    std::cout<<(8 ^ 9)<<"\n";
    std::cout<<(5<<2)<<"\n";
    std::cout<<(5>>2)<<"\n";

    (10 > 12) ? (std::cout<<"Hey\n") : (std::cout<<"how\n");
    return 0;
}