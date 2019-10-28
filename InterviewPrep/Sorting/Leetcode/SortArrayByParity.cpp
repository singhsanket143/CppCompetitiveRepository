#include <iostream>

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0, j = 0;
        while ( i < A.size() and j < A.size()) {
            if(i%2==0 and i < j) {
                i++;
                continue;
            }
            if(A[j]%2==0) {
                j+=2;
                continue;
            }
            if(A[i]%2==0) {
                swap(A[i], A[j]);
                i++;
                j+=2;
            } else {
                i++;
            }
        }
        return A;
    }
};
