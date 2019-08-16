#include<iostream>
#include<vector>
using namespace std;

// function to display an array.
void display(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isIdealPermutation(vector<int> &arr) {
    // write your code here.
    int n = arr.size();
    int *max_so_far = new int[n]();
    int *min_so_far = new int[n]();
    max_so_far[0] = 0;
    min_so_far[n - 1] = n - 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max_so_far[i - 1]]) {
            max_so_far[i] = i;
        } else {
            max_so_far[i] = max_so_far[i - 1];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[min_so_far[i + 1]]) {
            min_so_far[i] = i;
        } else {
            min_so_far[i] = min_so_far[i + 1];
        }
    }
    for (int i = 0; i < n; i++) {
        if (abs(max_so_far[i] - i) > 1 or abs(min_so_far[i] - i) > 1) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }

    if (isIdealPermutation(arr)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}