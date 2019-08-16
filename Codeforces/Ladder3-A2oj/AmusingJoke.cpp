#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[26] = {0};
	string s1, s2, s3;
	cin>>s1>>s2>>s3;
	for(int i=0;i<s1.length();i++) {
		arr[s1[i]-'A']++;
	}
	for(int i=0;i<s2.length();i++) {
		arr[s2[i]-'A']++;
	}
	for(int i=0;i<s3.length();i++) {
		arr[s3[i]-'A']--;
	}
	for(int i=0;i<26;i++) {
		if(arr[i]!=0){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}
