#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// --------------------------------------------------------
bool isTwoArrayEqual(vector<long> &num1, vector<long> &num2)
{
    // write your code here
    unordered_map<long, long> mp1;
    unordered_map<long, long> mp2;
    for (int i = 0; i < num1.size(); i++) {
        mp1[num1[i]]++;
    }
    for (int i = 0; i < num2.size(); i++) {
        mp2[num2[i]]++;
    }
    for (int i = 0; i < num1.size(); i++) {
        if (mp2.find(num1[i]) == mp2.end()) {
            return false;
        } else if (mp1[num1[i]] != mp2[num1[i]]) {
            return false;
        }
    }
    return true;
}
// --------------------------------------------------------

int main()
{
    int n = 0;
    cin >> n;
    vector<long> num(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int m = 0;
    //  cin >> m;
    vector<long> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (isTwoArrayEqual(num, arr))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}