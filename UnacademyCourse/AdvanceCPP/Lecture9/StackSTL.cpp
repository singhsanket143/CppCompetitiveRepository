#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <list>
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


int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	stack<int> s;
	vector<int> deq {3,1,2,4,5};
	int n;
	cin>>n;
	while(n--) {
		int x;
		cin>>x;
		s.emplace(x);
	}
	cout<<s.top()<<endl;
	s.pop();
	s.pop();
	cout<<s.top()<<endl;
	// s.pop_back();
	cout<<s.top()<<endl;;

	cout<<s.empty()<<endl;
	stack<int, vector<int> > st(deq);
	cout<<st.size()<<endl;
	st.push(12);
	cout<<st.size()<<endl;
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
