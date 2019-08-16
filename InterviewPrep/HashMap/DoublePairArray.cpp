#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) {
  return abs(x) < abs(y);
}
bool canReorder(int A[], int n) {
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    if (mp.find(A[i]) != mp.end()) {
      int temp = mp[A[i]];
      mp[A[i]] = temp + 1;
    } else
      mp[A[i]] = 1;
  }
  sort(A, A + n, cmp);
  for (int i = 0; i < n; i++) {
    if (mp.find(A[i]) == mp.end()) continue;
    if (mp.find(2 * A[i]) == mp.end()) return false;
    mp[A[i]] -= 1;
    mp[2 * A[i]] -= 1;
    if (mp[A[i]] == 0) mp.erase(A[i]);
    if (mp[2 * A[i]] == 0) mp.erase(2 * A[i]);
  }

  return true;
}

int main(int argc, char** argv) {
  int size;
  cin >> size;
  int a[size];
  for (int i = 0; i < size; i++) {
    cin >> a[i];
  }
  if (canReorder(a, size) == 0) {
    cout << "false" << endl;
  } else {
    cout << "true" << endl;
  }
}