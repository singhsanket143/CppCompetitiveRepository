#include<bits/stdc++.h>
#include<functional> // greater
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
	
	priority_queue<int> first;
	first.push(10);
	first.push(20);
	first.push(30);

	cout<<first.top()<<endl;

	first.pop();

	cout<<first.top()<<endl;

	priority_queue<int> second(first);

	cout<<second.top()<<endl;

	int arr[] = {4,2,7,1,-1,6,19};
	priority_queue<int> third(arr, arr+7);

	while(not third.empty()) {
		cout<<third.top()<<endl;
		third.pop();
	}

	// how to make a min heap 

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(10);
	pq.push(20);
	pq.emplace(30);
	cout<<pq.top()<<endl;


	// try to use priority_queue stl with some custom struct or classes HW
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
