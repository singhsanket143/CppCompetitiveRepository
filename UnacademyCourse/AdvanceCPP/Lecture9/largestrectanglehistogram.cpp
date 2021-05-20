
#include<iostream>
#include<stack>
#include<vector>
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

int maxArea(vector<int> &arr) {
	int n = arr.size();
	stack<int> s;
	int result = 0;
	int i;
	for(i = 0; i < n; ) {
		if(s.empty() or arr[s.top()] <= arr[i]) {
			// that means just an increasing value, push it
			s.push(i++);
		} else {
			int tp = s.top();
			s.pop();
			result = max(result, arr[tp]*(s.empty() ? i : i - s.top() - 1));
		}
	}
	while(not s.empty()) {
		int tp = s.top();
		s.pop();
		result = max(result, arr[tp]*(s.empty() ? i : (i - s.top() - 1)));
	}

	return result;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	vector<int> arr {6,2,5,4,5,1,6};
	cout<<maxArea(arr);

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
