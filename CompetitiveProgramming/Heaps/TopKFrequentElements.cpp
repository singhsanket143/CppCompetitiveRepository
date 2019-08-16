#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void Ktop(int *arr, int n, int k) {
	vector<int> top(k+1);
	unordered_map<int, int> freq;
	for(int m=0;m<n;m++) {
		freq[arr[m]]++;
		top[k] = arr[m];
		auto it = find(top.begin(), top.end()-1, arr[m]);
		for(int i=distance(top.begin(), it)-1;i>=0;i--) {
			if(freq[top[i]]<freq[top[i+1]]) {
				swap(top[i], top[i+1]);
			} else if(freq[top[i]]==freq[top[i+1]] and top[i]>top[i+1]) {
				swap(top[i], top[i+1]);
			} else {
				break;
			}
		}
		for (int i = 0; i < k && top[i] != 0; ++i) 
            cout << top[i] << ' '; 
	}
	
    cout<<endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	int t;
	cin>>t;
	while(t--) {
	  int n, k;
	  cin>>n>>k;
	  int *arr = new int[n];
	  for(int i=0;i<n;i++) {
	    cin>>arr[i];
	  }
	  Ktop(arr, n, k);
	  delete [] arr;
	}
	return 0;
}
