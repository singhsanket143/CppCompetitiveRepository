#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

void customerSolution(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if ((*it).second > 2 * k) {
            cout << 0;
            return ;
        }
    }
    cout << 1;
    return ;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    customerSolution(arr, k);
    cout << endl;
}

int main()
{
    solve();
    return 0;
}