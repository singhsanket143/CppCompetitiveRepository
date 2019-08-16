#include <iostream>
using namespace std;

void commonElements(int *a1, int *a2, int *a3, int n, int m, int o) {
	int i=0,j=0,k=0;
	while(i<n and j<m and k<o) {
		if(a1[i] == a2[j] and a2[j] == a3[k]) {
			cout<<a1[i]<<" ";
			i++;j++;k++;
		} else if(a1[i]<a2[j]) {
			i++;
		} else if(a2[j]<a3[k]) {
			j++;
		} else {
			k++;
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
