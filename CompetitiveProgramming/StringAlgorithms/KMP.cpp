#include <iostream>
#define MAX_N 100010
int preprocess[MAX_N];
using namespace std;

void KMPpreprocess(string pat) {
	int i = 0, j = -1; 
	preprocess[0] = -1;
	while(i < pat.length()) {
		while(j >= 0 and pat[i] != pat[j]) j = preprocess[j];
		i++;j++;
		preprocess[i] = j;
	}
	for(int i=0;i<pat.length()+1;i++) {
		cout<<preprocess[i]<<" ";
	}
	cout<<endl;
}

void KMPsearch(string str, string pat) {
	KMPpreprocess(pat);
	int i = 0, j = 0;
	while(i < str.length()) {
		while(j>=0 and str[i] != pat[j]) {
		    j = preprocess[j];
		}
		i++; j++;
		if (j == pat.length())
		{
			cout<<"Pattern is found at index "<<i-j<<endl;
			j = preprocess[j];
		}
	}
}

int main(int argc, char const *argv[])
{
	for(int i=0;i<MAX_N;i++) {
		preprocess[i] = -1;
	}
	string str, pat;
	cin>>str>>pat;
	KMPsearch(str, pat);
	return 0;
}
