#include<bits/stdc++.h>
using namespace std;

int nextGreaterElement(int n) {
    //Write your code here
    int retval = n;
    string str = to_string(n);
    int *number = new int[str.size()]();
    for (int i = str.size() - 1; i >= 0; i--) {
        number[i] = n % 10;
        n = n / 10;
    }
    int i;
    for (i = str.size() - 2; i >= 0; i--) {
        if (number[i] < number[i + 1]) {
            break;
        }
    }
    if (i < 0) {
        return -1;
    }
    int j;
    for (int j = str.size() - 1; j > i; j--) {
        if (number[j] > number[i]) {
            swap(number[i], number[j]);
            break;
        }
    }

    sort(number + i + 1, number + str.size());
    long long int result = 0;
    for (int x = 0; x < str.size(); x++) {
        result = 10 * result + number[x];
    }
    if (result > INT_MAX) return -1;
    return (int)result;
}

int main(int argc, char** argv) {
    int n; cin >> n;
    cout << nextGreaterElement(n);
}