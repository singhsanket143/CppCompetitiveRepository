#include<iostream>
#include<vector>
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input a String S and an integer array shifts.
// It should return the final string after all the shifts are applied.
string shiftingLetters(string &s, vector<int> &shifts) {
    // write your code here.
    int n = shifts.size();
    long long int *cumsum = new long long int[n]();
    cumsum[n - 1] = shifts[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        cumsum[i] = cumsum[i + 1] + shifts[i];
    }
    for (int i = 0; i < n; i++) {
        int ch = s[i] - 'a';
        char newch = (char)(((ch + cumsum[i]) % 26) + 'a');
        s[i] = newch;
    }
    return s;
}

int main(int argc, char** argv) {
    string s;
    cin >> s;
    int N;
    cin >> N;

    vector<int> shifts(N);

    for (int i = 0; i < N; i++) {
        cin >> shifts[i];
    }

    cout << shiftingLetters(s, shifts);
}