// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
void file_i_o()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
}

class Product {
public:
    int price;
    std::string name;

    // default constructor
    Product() {} // not mandatory to write

    // Parameterised constructor
    // Product(int price, std::string name) {
    //     this->price = price;
    //     this->name = name;
    // }

    Product(int p, std::string n) : price(p), name(n) {}

    Product(std::string name) {
        this->name = name;
    }

    ~Product() {
        std::cout<<"Destructed";
    }
};

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    Product p1; // init in stack
    Product *p2 = new Product; // init in heap
    Product *p3 = new Product(); // init in heap
    Product p4; // init in stack

    Product p5(100000,"Iphone");
    Product *p6 = new Product(40000, "Pixel");

    Product p7("Redmi");

    return 0;
}