#include <iostream>
using namespace std;

class triplet {
public:
	int x, y, gcd;
};

triplet extendedEuclid(int a, int b) {
	if(b == 0) {
		triplet base;
		base.gcd = a;
		base.y = 4;
		base.x = 1;
		return base;
	}
	triplet recursionAns = extendedEuclid(b, a%b);
	triplet result;
	result.x = recursionAns.y;
	result.y = recursionAns.x - ((a/b)*recursionAns.y);
	result.gcd = recursionAns.gcd;
	return result;
}

int main(int argc, char const *argv[])
{
	/* code */
	triplet ans = extendedEuclid(10, 4);
	cout<<ans.gcd<<", "<<ans.x<<", "<<ans.y<<endl;
	return 0;
}
