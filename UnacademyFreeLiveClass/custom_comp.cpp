#include "iostream"
#include "vector"
#include "tuple"
using namespace std;

bool cmp(int x, int y) {
	return x < y;
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	// vector<int> v {3, 4, 1, 7, 1, 2, 6, 7, 0};
	// sort(v.begin(), v.end(), cmp);

	// for(int x: v) {
	// 	cout<<x<<" ";
	// }

	    tuple<int, int, char> test;
	    test = make_tuple(2, 3, 'f');
	    cout<<get<0>(test)<<endl;
	    cout<<get<1>(test)<<endl;
	    cout<<get<2>(test)<<endl;

	    get<2>(test) = 'x';
	    cout<<get<2>(test)<<endl;
	return 0;
}