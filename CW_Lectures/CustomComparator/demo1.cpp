#include <iostream>
#include <vector>
using namespace std;

class Product {
    public:
    int price;
    string name;

    Product(int p, string n) {
        this->price = p;
        this->name = n;
    }
};

bool cmp( Product& p1,  Product& p2) {
    return p1.price < p2.price; // product having lesser price will be picked
}

int main() {

    vector<Product> v;

    Product p1(100, "abc");
    Product p2(10, "def");
    Product p3(45, "ghi");

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < 3; i++) {
        cout<<v[i].name<<" ";
    }

    return 0;
}
