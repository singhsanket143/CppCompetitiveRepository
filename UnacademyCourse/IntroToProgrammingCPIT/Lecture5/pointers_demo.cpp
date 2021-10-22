#include<iostream>

int main() {

    int x = 10;
    int* p1 = &x;
    int** p2 = &p1;
    int*** p3 = &p2;
    auto p4 = &p3;
    std::cout<<x<<" "<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<"\n";

    int y = *p1;
    std::cout<<y<<"\n";
    *p1 = 9;
    std::cout<<y<<" "<<x<<"\n";
    std::cout<<*p1<<"\n";

    return 0;
}