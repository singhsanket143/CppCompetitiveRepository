#include <bits/stdc++.h>
#define inf 1000000000000
using namespace std;

class Point {
public:
	double x,y;
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

double dist(Point *p1, Point *p2) {
	return sqrt(((p1->x - p2->x)*(p1->x - p2->x)) + ((p1->y - p2->y)*(p1->y - p2->y)));
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	Point *arr[n];
	double fi[n];
	double dp[n+1];
	for(int i=0;i<=n;i++) {
		dp[i] = 0.0;
	}
	for(int i=0; i<n; i++) {
		double a,b,c;
		cin>>a>>b;
		arr[i] = new Point(a,b);
		cin>>c;
		fi[i] = c;
	}
	dp[0] = fi[0];
	for(int i = 1; i < n; i++) {
        dp[i] = -inf;
		for(int j = 0; j < i; j++) {
			dp[i] = max(dp[i], dp[j] - dist(arr[i], arr[j]));
		}
		dp[i] += fi[i];

	}
    cout<<fixed;
	cout<<setprecision(6)<<dp[n-1];

	return 0;
}
