#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n, m;
		cin>>n>>m;
		string str;
		
		int arr[n][m];
		for(int i=0;i<n;i++) {
			cin>>str;
			for(int j=0;j<m;j++) {
				if(str[j] == '0') {
					arr[i][j] = 0;
				} else {
					arr[i][j] = 1;
				}
			}
		}
		int dist[10000] = {0};
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				int x = i, y=j;
				if(arr[i][j]==0){
					continue;
				}
				for(int l=i;l<n;l++) {
					for(int k=(l==i)?(j+1):0;k<m;k++) {
						if(arr[l][k]==1) {
							int d = abs(x-l)+abs(y-k);
							// cout<<d<<endl;
							dist[d]++;
						}
					}
				}
			}
		}
		for(int i=1;i<=abs(n+m-2);i++) {
			cout<<dist[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
