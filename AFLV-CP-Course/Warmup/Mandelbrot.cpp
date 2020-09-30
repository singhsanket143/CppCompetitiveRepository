// Problem Link - https://open.kattis.com/problems/mandelbrot
/* By Sanket Singh */
#include<bits/stdc++.h>
#define ll 				long long int
#define mod             1000000007
#define inf             1e18
#define DEBUG(x) 		cout << '>' << #x << ':' << x << endl;
using namespace std;
class Complex {
public:
	double real, img;
	Complex(double real, double img) {
		this->real = real;
		this->img = img;
	}
};

double magnitude(Complex *c) {
	return sqrt((c->real*c->real) + (c->img*c->img));
}

Complex* square(Complex *c) {
	return new Complex((c->real*c->real)-(c->img*c->img), 2*c->real*c->img);
}

Complex* add(Complex *c1, Complex *c2) {
	return new Complex(c1->real+c2->real, c1->img+c2->img);
}

void print(Complex *c) {
	printf("%lf + i%lf\n", c->real, c->img);
}
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

int main(int argc, char const *argv[]) {
	file_i_o();
	double x, y;
	ll r, count = 1;
	bool flag = false;
	while(scanf("%lf %lf %lld", &x, &y, &r) != EOF) {
		Complex *z = new Complex(0, 0);
		Complex *c = new Complex(x, y);
		r++;
		while(r-- > 0) {
			ll mag = magnitude(z);
			if(isgreater(mag, 2.0)) {
				//printf("Case %lld: OUT\n", count++);
				flag = true;
				;
			}
			Complex *sq = square(z);
			Complex *temp = add(sq, c);
			z->real = temp->real;
			z->img = temp->img;
			
			
			delete sq;
			delete temp;
		}
		ll mag = magnitude(z);
		if(!flag) {
			printf("Case %lld: IN\n", count++);
		} else {
			printf("Case %lld: OUT\n", count++);
		}
		flag = false;
	}
	return 0;
}
