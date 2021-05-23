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

void forEach() {
	// some task
}
namespace B {
	void print(const char *s) {
		std::cout<<"from b's namespace "<<s<<std::endl;
	}
}

namespace A {
	namespace C {
		void print(const string &s) {
			std::cout<<"from A's namespace "<<s<<endl;
		}
	}
	
}


using namespace B;
using namespace A;
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	
	string s("hi");
	A::C::print("hi");
	vector<int> v {5,4,3,2,1};
	sort(v.begin(), v.end());
	forEach();

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
