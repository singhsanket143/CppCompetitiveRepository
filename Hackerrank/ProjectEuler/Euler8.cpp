#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        string str;
        cin>>n>>k;
        cin>>str;
        long long int max_product = INT_MIN;
        
        long long int curr_product = 1;
        for(int i=0;i<str.size()-k;i++) {
        	curr_product = 1;
        	for(int j=0;j<k;j++) {
        		curr_product*= str[i+j]-'0';
        	}
            if(curr_product > max_product) {
                max_product =curr_product;
            }
        }
        cout<<max_product<<endl;
    }
    return 0;
}

