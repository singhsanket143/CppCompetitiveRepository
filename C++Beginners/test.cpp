
#include<iostream>
using namespace std;
int main() {
char a[100];
cin>>a;
int i=0;
if(a[0]=='9'){ cout<<a[0];i++; }
for(;a[i]!=0;i++)
{
int digit=a[i]-'0';
if(digit>=5)
cout<<(9-digit);
else cout<<digit;
}
return 0;
}