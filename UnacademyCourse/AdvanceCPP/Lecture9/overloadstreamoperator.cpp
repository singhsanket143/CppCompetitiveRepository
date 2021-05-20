#include<iostream>
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

class Complex {
public:
	int real;
	int img;
	Complex(int real, int img) : real(real), img(img) {}
	friend ostream& operator << (ostream &o, Complex &c);
	friend istream& operator >> (istream &i, Complex &c);

	void operator >>(Complex &c) {
		cout<<this->real+c.real<<endl;
	}
};

ostream& operator <<(ostream& o, Complex& c) {
	o<<c.real<<" + i"<<c.img;
	return o;
}

istream& operator >>(istream& i, Complex& c) {
	i>>c.real;
	i>>c.img;
	return i;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	Complex c(2, 3);
	cout<<c<<endl;
	Complex c2(4, -3);
	c>>c2;
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
