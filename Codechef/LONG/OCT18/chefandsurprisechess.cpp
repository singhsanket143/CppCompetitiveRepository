#include <iostream>
#include<math.h>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#define ll long long int
using namespace std;


void query(ll *mM, int n) {
	int q;
	cin>>q;
	for(int i=0;i<q;i++) {
		long long int num;
		cin>>num;
		for (int i = n - 1; i >= 0; i--) {
                if (mM[i] <= num) {
                    cout<<i<<endl;
                    break;
                }
        }
	}

}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	int mL = min(m,n);
	ll *mM = new ll(mL+1);
	int **arr = new int*[n];
	for(int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	f(5);
	for(int i = 0; i < n; i++) {
		string str;
		cin>>str;
		for(int j = 0; j < m; j++) {
			arr[i][j] = str[j]-'0';
		}
	}
	// int **solution = new int*[n];
	// for(int i = 0; i < n; i++) {
	// 	solution[i] = new int[m];
	// }
	ll solution[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			solution[i][j]=0;
		}
	}
	solution[0][0] = arr[0][0];
	int count = 0;
	for(int i = 1; i < m; i++) {
		if(i%2 != 0 and arr[0][i] != 1) {
			solution[0][i] = solution[0][i-1]+1;
		} else if(i%2 == 0 and arr[0][i] != 0) {
			solution[0][i] = solution[0][i-1]+1;
		} else {
			solution[0][i] = solution[0][i-1];
		}
	}
	
	for(int i = 1; i < n; i++) {
		if(i%2 != 0 and arr[i][0] != 1) {
			solution[i][0] = solution[i-1][0]+1;
		} else if(i%2 == 0 and arr[i][0] != 0) {
			solution[i][0] = solution[i-1][0]+1;
		} else {
			solution[i][0] = solution[i-1][0];
		}
	}
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			int cand = ((i+j)%2==arr[i][j])?0:1;
			solution[i][j] = solution[i-1][j]+solution[i][j-1]-solution[i-1][j-1]+cand;
		}
	}

	// for (int i = 0; i < mL; i++) {
	// 	ll a = solution[i][i];
	// 	ll b = ((i+1)*(i+1));
	// 	ll c = b-a;
	// 	mM[i+1] = min(a, c);
 //    }
	mM[0] = 0;
    for(int i = 0; i <mL; i++) {
    	mM[i+1] = min(solution[i][i], (i+1)*(i+1)-solution[i][i]);
    }
    
    // for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < m; j++) {
	// 		cout<<solution[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
    for(int i = 1; i < n; i++) {
    	for(int j = 0; j < mL; j++) {
    		if(i+j < n) {
    			ll r = solution[i+j][j] - solution[i-1][j];
    			mM[j+1] = min(mM[j+1], min(r, (j+1)*(j+1) - r));
    		} else {
    			break;
    		}
    	}
    }
    // for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < m; j++) {
	// 		cout<<solution[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
    for(int i = 1; i < m; i++) {
    	for(int j = 0; j < mL; j++) {
    		if(i+j < m) {
    			ll r = solution[j][i+j] - solution[j][i-1];
    			mM[j+1] = min(mM[j+1], min(r, (j+1)*(j+1) - r));
    		} else {
    			break;
    		}
    	}
    }

    // for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < m; j++) {
	// 		cout<<solution[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
    for(int i = 1; i < n; i++) {
    	for(int j = 1; j < m; j++) {
    		for(int k=0; k <mL; k++) {
    			if(i+k < n and j+k < m) {
	    			ll r = solution[i+k][j+k] - solution[i-1][j+k] - solution[i+k][j-1] + solution[i-1][j-1];
	    			mM[k+1] = min(mM[k+1], min(r, (k+1)*(k+1) - r));
	    		} else {
	    			break;
	    		}
    		}
    	}
    }
	// for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < m; j++) {
	// 		cout<<solution[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	query(mM, mL+1);
	return 0;
}
