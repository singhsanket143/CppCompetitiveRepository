#include <iostream>
#include <queue>
#define ll long long int
using namespace std;

ll rocket(ll x, ll y){
	return x*x + y*y;
}

int main(int argc, char const *argv[])
{
	int q, k;
	cin>>q>>k;
	priority_queue<ll> pq;
	while(q--) {
		int type;
		cin>>type;

		if(type==2) {
			cout<<pq.top()<<endl;;
		} else if(type == 1) {
			ll x, y;
			cin>>x>>y;
			if(pq.size() == k) {
				// work
				if(rocket(x, y) > pq.top()) {
					// No work
				} else {
					pq.pop();
					pq.push(rocket(x, y));
				}
			} else if(pq.size() < k) {
				pq.push(rocket(x, y));
			}
		}
	}
	return 0;
}