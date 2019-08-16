#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int global_arr[1000005];
class circle {
public:
	long long int x,y,r;

	circle(int x, int y, int r) {
		this->x = x;
		this->y = y;
		this->r = r;
	}
};

void initialize() {
	for(int i=0;i<=1000001;i++) {
		global_arr[i]=0;
	}
} 

void cumulativeSum() {
	for(int i=1;i<=1000000;i++) {
		global_arr[i] = global_arr[i]+global_arr[i-1];
	}
}

int checkDecimal(double a) {
	if(int(a) != a) {
		return 1;
	} else {
		return 0;
	}
	// int t=a;
	// if((a-t)!=0){
	// 	return 1;
	// }
	// return 0;
}

int main(int argc, char const *argv[])
{
	int n, q, a, b, c;
	cin>>n>>q;
	int *freq = new int[1000];
	circle* arr[n];
	for(int i = 0; i < n; i++) {
		cin>>a>>b>>c;
		arr[i] = new circle(a, b, c);
	}
	initialize();
	
	pair<ll, ll> precompute[1001][1001];
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			circle *c1 = (arr[i]->r >= arr[j]->r)?arr[i]:arr[j];
			circle *c2 = (arr[i]->r >= arr[j]->r)?arr[j]:arr[i];
			int t1 = (c1->r >= c2->r)?(c1->r):(c2->r);
			int t2 = (c1->r >= c2->r)?(c2->r):(c1->r);
			double dist = sqrt(((c1->x - c2->x)*(c1->x - c2->x))+((c1->y - c2->y)*(c1->y - c2->y)));
			long long int minimum, maximum;
			if(c1->x == c2->x and c1->y == c2->y) {
				precompute[i][j] = make_pair((c1->r-c2->r), (c1->r+c2->r));
				minimum = precompute[i][j].first;
				maximum = precompute[i][j].second;
				//minimum = minimum + checkDecimal(dist);

			}  else if(dist >= (c1->r+c2->r)) { // case 1
				// cout<<"In 2"<<dist<<" "<<c1->r<<" "<<c2->r<<endl;
				precompute[i][j] = make_pair((dist-c1->r-c2->r), (dist+(c1->r+c2->r)));
				minimum = precompute[i][j].first;
				maximum = precompute[i][j].second;
				minimum = minimum + checkDecimal(dist);

			}   else if((dist + c2->r) <= c1->r) { // case 4
				// if(c1->r > c2->r) {
				// 	precompute[i][j] = make_pair(abs(c1->r-dist-c2->r), abs(c1->r+dist+c2->r));
				// } else {

				// 	precompute[i][j] = make_pair(abs(c2->r-dist-c1->r), abs(c2->r+dist+c1->r));
				// }
				precompute[i][j] = make_pair((c1->r-c2->r-dist), (c1->r+dist+c2->r));
				minimum = precompute[i][j].first;
				maximum = precompute[i][j].second;
				minimum = minimum + checkDecimal(dist);

			} 	else { // case 6
					precompute[i][j] = make_pair(0, (c1->r+dist+c2->r));
					minimum = precompute[i][j].first;
					maximum = precompute[i][j].second;
					//minimum = minimum + checkDecimal(dist);
			}
			// cout<<minimum<<" "<<maximum<<endl;
			global_arr[minimum] = global_arr[minimum] + 1;
			global_arr[maximum+1] = global_arr[maximum+1] - 1;
		}
	}

	// for(int i = 0; i < n; i++) {
	// 		for(int j = i+1; j < n; j++) {
	// 			cout<<precompute[i][j].first<<" "<<precompute[i][j].second<<endl;
	// 		}
	// 	}
	cumulativeSum();
	while(q--) {
		int k;
		cin>>k;
		cout<<global_arr[k]<<endl;
	}
	return 0;
}
