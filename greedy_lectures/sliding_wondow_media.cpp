#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

double getMedian(priority_queue<int> &left, priority_queue<int, vector<int>, greater<int> > &right, int x, int y) {
    int totalSize = x+y;
    if(totalSize % 2 != 0) {
        // odd
        return right.top();
    } else {
        // even
        return (left.top() + right.top())/ 2.0;
    }
}

bool isBalanced(int x, int y) {
    return (x == y) or (x + 1 == y);
}

vector<double> sliding_median(vector<int> &arr, int n, int k) {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int> > right;
    int x = 0, y = 0;
    right.push(arr[0]); // indexes
    y++;
    for(int i = 1; i < k; i++) {
        int curr = arr[i];
        double med = getMedian(left, right, x, y);
        if(curr < med) {
            // go left
            left.push(curr);
            x++;
            if(!isBalanced(x, y)) {
                int toberemoved = left.top();
                left.pop();
                right.push(toberemoved);
                x--; y++;
            }
        } else {
            // go right
            right.push(curr);
            y++;
             if(!isBalanced(x, y)) {
                 int toberemoved = right.top();
                right.pop();
                left.push(toberemoved);
                y--; x++;
            }
        }
    }
    double m = getMedian(left, right, x, y); // answer of first window

    vector<double> result;
    result.push_back(m);
    unordered_map<int, int> mp;
    for(int i = k; i < n; i++) {
        int newElementIndex = i;
        int oldElementToBeDeleted = i - k; 
        double med = getMedian(left, right, x, y);
        if(arr[newElementIndex] > med) {
            // go right
            right.push(arr[newElementIndex]);
            y++;
            if(!isBalanced(x, y)) {
                int toberemoved = right.top();
                right.pop();
                left.push(toberemoved);
                y--; x++;
            }
        } 
        else {
            // go left
            left.push(arr[newElementIndex]);
            x++;
            if(!isBalanced(x, y)) {
                int toberemoved = left.top();
                left.pop();
                right.push(toberemoved);
                x--; y++;
                
            }
        }
        mp[arr[oldElementToBeDeleted]] = oldElementToBeDeleted;
        if(arr[oldElementToBeDeleted] > getMedian(left, right, x, y)) {
            y--;
        } else {
            x--;
        }
        while(!left.empty() and mp.count(left.top())) {
            mp.erase(left.top());
            left.pop();
            // x--;
            if(!isBalanced(x, y)) {
                int toberemoved = right.top();
                right.pop();
                left.push(toberemoved);
                y--; x++;
            }

        } 
        while(!right.empty() and mp.count(right.top())) { //mp[right.top] => 0
            mp.erase(right.top());
            right.pop();
            // y--;
            if(!isBalanced(x, y)) {
                int toberemoved = left.top();
                left.pop();
                right.push(toberemoved);
                x--; y++;
            }
        } 
        
        result.push_back(getMedian(left, right, x, y));
    }
    return result;
}

int main() {
    // Fast io
    // ios_base::sync_with_stdio(0); 
    // cin.tie(0); 
    // cout.tie(0);
    // Fast io
    // int t = 1;
    // cin>>t;
    int n = 9;
    int k = 3;
    // cin>>n>>k;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(2);

    vector<double> ans = sliding_median(arr, n, k);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<"\n";
    }
    // cout<<"inmain\n";
    return 0;
}

// 8
//3
//1 3 -1 -3 5 3 6 7    
//