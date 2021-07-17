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
private:
    int price = 10;
    std::string name;
    mutable int u;
public:
    Product() {}
    int get_price() const {
        u = 99;
        return this->price;
    }
    std::string get_name() {
        return this->name;
    }
    
};

void print_product(const Product& p) {
    std::cout<<p.get_price()<<"\n";
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    
    Product p;
    std::cout<<p.get_price()<<"\n";
    
    return 0;
}