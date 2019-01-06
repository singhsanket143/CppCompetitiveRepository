#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int visited[10005];
int findMinSwaps(int *arr, int n) {
	std::vector<pair<int, int> > v;
	int ans=0;
	for(int i=0;i<n;i++) {
		v.push_back({arr[i], i});
	}
	sort(v.begin(), v.end());
	for(int i=0;i<n;i++) {
		if(visited[i] or v[i].second == i)
			continue;
		int cycle_size = 0;
		int j = i;
		while(!visited[j]) {
			visited[j] = 1;
			j = v[j].second;
			cycle_size++;
		}
		ans+=cycle_size-1;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
