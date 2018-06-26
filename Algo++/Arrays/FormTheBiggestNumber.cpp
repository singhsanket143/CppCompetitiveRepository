#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);

    // then append X at the end of Y
    string YX = Y.append(X);

    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1: 0;
}
int main(int argc, char* argv[])
{
    int t;
    int n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<string> arr;
        for(int i=0;i<n;i++) {
            string temp;
            cin>>temp;
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end(), myCompare);
        for(int i=0;i<n;i++) {
            cout<<arr[i];
        }
        cout<<endl;
    }

    return 0;
}
