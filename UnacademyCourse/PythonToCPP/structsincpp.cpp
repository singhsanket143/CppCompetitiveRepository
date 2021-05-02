#include<iostream>
using namespace std;

struct Product {
	// data memeber
	int cost; // initiasing here wont work below c++ 11
	string name;
	string desc;
	int product_id;

	// Member functions
	void display() {
		cout<<"Name of the product is "<<name<<" and cost is "<<cost<<endl;
	}
};


int main()
{
	/* code */
	struct Product p1 = {10, "Pencil", "This is a pencil", 1};
	p1.display();
	p1.cost = 99; // update the data members of a struct
	p1.display();
	return 0;
}