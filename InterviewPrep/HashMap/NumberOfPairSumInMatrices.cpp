#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input two matrices and k.
// It should return the count of pairs with sum k.
int solve(vector<vector<int> > & mat1, vector<vector<int> >& mat2, int k) {
    // write your code here.
    unordered_map<int, int> mp;
    for (int i = 0; i < mat1.size(); i++) {
        for (int j = 0; j < mat1[0].size(); j++) {
            mp[mat1[i][j]]++;
        }
    }
    int count = 0;
    for (int i = 0; i < mat2.size(); i++) {
        for (int j = 0; j < mat2[0].size(); j++) {
            if (mp.find(k - mat2[i][j]) == mp.end()) {
                // nothing
            } else {
                count += mp[k - mat2[i][j]];
            }
        }
    }
    return count;
}


int main(int argc, char** argv) {

    int n;
    cin >> n;
    vector< vector<int> > mat1(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat1[i][j];
        }
    }
    vector< vector<int> > mat2(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat2[i][j];
        }
    }
    int k;
    cin >> k;
    cout << solve(mat1, mat2, k) << endl;
}