#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input the array and K.
// You have to return true if array can be divided, else should return
// false.

bool SubsetProblem(vector<int> arr1, vector<int> arr2)
{
  unordered_map<int, int> mp1, mp2;
  for (int i = 0; i < arr1.size(); i++) {
    mp1[arr1[i]]++;
  }
  for (int i = 0; i < arr2.size(); i++) {
    if (mp1.find(arr2[i]) == mp1.end()) {
      return false;
    } else {
      mp1[arr2[i]]--;
      if (mp1[arr2[i]] == 0) {
        mp1.erase(arr2[i]);
      }
    }
  }
  return true;
}

void solve()
{
  int n, m;
  cin >> n;

  vector<int> arr1(n, 0);


  for (int i = 0; i < n; i++)
  {
    cin >> arr1[i];
  }
  cin >> m;
  vector<int> arr2(m, 0);
  for (int i = 0; i < m; i++)
  {
    cin >> arr2[i];
  }

  bool x = SubsetProblem(arr1, arr2);
  if (x == true) cout << "Yes";
  else cout << "No";

}

int main(int args, char **argv)
{
  solve();
  return 0;
}