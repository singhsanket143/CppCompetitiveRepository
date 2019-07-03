#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class fraction {
public:
    double value;
    int i;
    int j;
    fraction(double v, int ir, int jr) {
        value = v;
        i = ir;
        j = jr;
    }
    bool operator < (const fraction &x) const {
        return value > x.value;
    }
};
vector<int> kthSmallestPrimeFraction(vector<int>& A, int k) {
    priority_queue<fraction> pq;
    for (int i = 0; i < A.size(); i++) {
        pq.push(fraction(static_cast<double>(A[i]) / A.back(), i, A.size() - 1));
    }
    while (k > 1) {
        k--;
        auto t = pq.top();
        pq.pop();
        t.j = t.j - 1;
        pq.push(fraction(static_cast<double>(A[t.i]) / A[t.j], t.i, t.j));
    }
    return {A[pq.top().i], A[pq.top().j]};
}

int main()
{
    int k, n;
    cin >> k >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    arr = kthSmallestPrimeFraction(arr, k);
    //  for (int i : arr)
    //  {
    cout << arr[0] << "/" << arr[1];
    //  }
    cout << endl;
}