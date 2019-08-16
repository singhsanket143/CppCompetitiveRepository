#include <iostream>
using namespace std;

void display(int **sol, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout<<(to_string(sol[i][j]) + "\t");
			}
			cout<<"\n";
		}
}

bool isitsafe(int x, int y, int **sol, int n) {
		return (x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1);
}

bool knighttour(int cr, int cc, int **sol, int n, int csf) {
		if (csf == n*n) {
			return true;
		}
		if (isitsafe(cr + 2, cc + 1, sol, n)) {
			sol[cr + 2][cc + 1] = csf;
			if (knighttour(cr + 2, cc + 1, sol, n, csf + 1))
				return true;
			else
				sol[cr + 2][cc + 1] = -1;

		}
		if (isitsafe(cr + 1, cc + 2, sol, n)) {
			sol[cr + 1][cc + 2] = csf;
			if (knighttour(cr + 1, cc + 2, sol, n, csf + 1))
				return true;
			else
				sol[cr + 1][cc + 2] = -1;

		}
		if (isitsafe(cr + 1, cc - 2, sol, n)) {
			sol[cr + 1][cc - 2] = csf;
			if (knighttour(cr + 1, cc - 2, sol, n, csf + 1))
				return true;
			else
				sol[cr + 1][cc - 2] = -1;

		}
		
		if (isitsafe(cr + 2, cc - 1, sol, n)) {
			sol[cr + 2][cc - 1] = csf;
			if (knighttour(cr + 2, cc - 1, sol, n, csf + 1))
				return true;
			else
				sol[cr + 2][cc - 1] = -1;

		}
		if (isitsafe(cr - 1, cc + 2, sol, n)) {
			sol[cr - 1][cc + 2] = csf;
			if (knighttour(cr - 1, cc + 2, sol, n, csf + 1))
				return true;
			else
				sol[cr - 1][cc + 2] = -1;

		}
		if (isitsafe(cr - 1, cc - 2, sol, n)) {
			sol[cr - 1][cc - 2] = csf;
			if (knighttour(cr - 1, cc - 2, sol, n, csf + 1))
				return true;
			else
				sol[cr - 1][cc - 2] = -1;

		}
		if (isitsafe(cr - 2, cc + 1, sol, n)) {
			sol[cr - 2][cc + 1] = csf;
			if (knighttour(cr - 2, cc + 1, sol, n, csf + 1))
				return true;
			else
				sol[cr - 2][cc + 1] = -1;

		}
		if (isitsafe(cr - 2, cc - 1, sol, n)) {
			sol[cr - 2][cc - 1] = csf;
			if (knighttour(cr - 2, cc - 1, sol, n, csf + 1))
				return true;
			else
				sol[cr - 2][cc - 1] = -1;

		}
		return false;
	}

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	int **sol = new int*[n];
	for(int i=0;i<n;i++) {
		sol[i] = new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) {
			sol[i][j] = -1;
		}
	}
	sol[0][0] = 0;

	if (knighttour(0, 0, sol, n, 1)) {
			display(sol, n);
	} else {
			cout<<("no");
	}
	return 0;
}
