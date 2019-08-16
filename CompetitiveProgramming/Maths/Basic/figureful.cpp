#include "iostream"
#include "map"
using namespace std;
typedef pair<int, int> pr;

int main(int argc, char* argv[])
{
    map<pr, string> mp;
    int n;
    cin >> n;
    while(n--) {
        pr code;
        string str;
        cin>>code.first>>code.second;
        cin>>str;
        mp[code] = str;
    }
    int t;
    cin>>t;
    while(t--) {
        pr test_code;
        cin>>test_code.first>>test_code.second;
        cout<<mp[test_code]<<endl;
    }

    return 0;
}
