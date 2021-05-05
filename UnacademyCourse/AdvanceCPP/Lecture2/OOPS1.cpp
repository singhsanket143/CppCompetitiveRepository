#include<bits/stdc++.h>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

class Product { // this is a blue print
	string name; // data members
	int cost;
	int discount;

	// own constructor

public:
	Product() {} // default constrcutor

	Product(string n, int c) {
		name = n;
		cost = c;
	}

	Product(string name, int c, int d) {
		this->name = name;
		this->cost = c;
		discount = d;
	}

	void display() {
		cout<<name<<" "<<cost<<" "<<discount<<endl;
	}

	void setCost(int c) { // setter
		if(c < 0) return;
		cost = c;
	}

	int getCost() { // getter
		return cost;
	}

};

struct Player {
private:
	int x, y;
};


int main(int argc, char const *argv[]) {
	file_i_o();
	// Write your code here....
	Product iphone("Iphone 11", 100000, 30); // calls default constructor
	Product shirt("blue mens shrt", 2000);
	// shirt.name = "blue mens shirt";
	// iphone.display();
	// shirt.display();
	// cout<<shirt.name<<endl;
	shirt.display();
	shirt.setCost(3000);
	shirt.display();
	cout<<sizeof(iphone)<<" "<<sizeof(shirt)<<endl;
	Product *p = &iphone;
	cout<<p->getCost()<<endl; // access by pointer
	cout<<(*p).getCost()<<endl; // access by dereferencing object
	cout<<"Ended";
	
	struct Player p1;
	p1.x = 10;

	return 0;
}
