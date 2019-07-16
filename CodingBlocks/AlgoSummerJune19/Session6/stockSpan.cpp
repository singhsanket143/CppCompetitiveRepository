#include <iostream>
#include <stack>
using namespace std;

void stockspan(int arr[6], int n){
	stack<int> st;
	int ans[6] = {0};
	for (int i = 0; i < n; i++)
	{	
		int curr_val = arr[i];
		while(st.empty() == false &&  curr_val>arr[st.top()]){
			st.pop();
		}
		int better_day = st.empty()? 0 : st.top();
		int span = i - better_day;
		if(better_day == 0){
			span =0;
		}
		ans[i] = span;
		st.push(i);
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<ans[i]<<", ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{	
	int n =6;
	int arr[6] = {100, 200, 300, 400, 500, 600};

	stockspan(arr, n);

	return 0;
}