#include<iostream>
#include<cstring>
using namespace std;
void replacePi(string str,string osf)
{
    if(str.size()==1)
    {
        cout<<osf<<endl;
        return;
    }
    
    if(str[0]=='p'&&str[1]=='i')
    {
        replacePi(str.substr(2),osf+"3.14");
    }
    else
    {
        replacePi(str.substr(1),osf+str[0]);
    }
}
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string str;
        cin>>str;
        replacePi(str,"");
    }
	return 0;
}
