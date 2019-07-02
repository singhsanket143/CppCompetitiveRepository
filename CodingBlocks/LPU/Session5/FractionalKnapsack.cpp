#include <iostream>
using namespace std;

class Item {
public:
	int weight;
	int value;
};

bool cmp(Item a, Item b) {
	double r1 = (double)a.value/a.weight;
	double r2 = (double)b.value/b.weight;

	return r1<r2;
}






int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	Item arr[n];
	for(int i=0;i<n;i++) {
		int a, b;
		cin>>a>>b;
		arr[i].weight = a;
		arr[i].value = b;
	}
	int capacity;
	cin>>capacity;
	sort(arr, arr+n, cmp);
	double result = 0;
	double curr_weight = 0;
	for(int i=n-1;i>=0;i--) {
		if(arr[i].weight+curr_weight <= capacity) {
			result += arr[i].value;
			curr_weight+=arr[i].weight;
		} else {
			int diff = capacity - curr_weight;
			double temp = diff*((double)arr[i].value/arr[i].weight);
			result+=temp;
			break;
		}
	}
	cout<<result;
	return 0;
}
