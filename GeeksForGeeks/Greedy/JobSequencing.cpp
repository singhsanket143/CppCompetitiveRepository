#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class jobs {
public:
	char jobID;
	int deadLine;
	int profit;
	
};

bool cmp(jobs J1, jobs J2) {
	return J1.profit>J2.profit;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	jobs arr[n];
	for(int i=0;i<n;i++) {
		char a='a';
		int b, c;
		// cin>>a>>b>>c;
		cin>>b>>c;
		arr[i].jobID = a;
		arr[i].deadLine = b;
		arr[i].profit = c;
	}
	sort(arr, arr+n, cmp);
	int counter = 0;
	bool slots[n];
	for(int i=0;i<n;i++) slots[i] = false;
	int result[n];

	for(int i=0;i<n;i++) {
		for(int j = min(n, arr[i].deadLine)-1;j>=0;j--) {
			if(slots[j]==false) {
				slots[j]=true;
				result[j]=i;
				counter++;
				break;
			}
		}
	}
	int profit=0;
	for(int i=0;i<n;i++) {
		if(slots[i]==true) profit+=arr[result[i]].profit;
	}
	cout<<counter<<" "<<profit;
	return 0;
}
