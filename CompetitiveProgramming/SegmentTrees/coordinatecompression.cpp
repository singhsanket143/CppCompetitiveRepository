#include<iostream>
#include<map>
#include<vector>
#define ll long long int

std::map<int, int> mp;
int ptr = 0;

std::vector<int> L, R, T;

int main(int argc, char const *argv[])
{
    /* code */
    int q;
    std::cin>>q;
    for(int i = 0; i < q; i++) {
        int t;
        std::cin>>t;
        T[i] = t;
        if(t == 1) { // update
            int k, val;
            std::cin>>k>>val;
            L[i] = k;
            mp[k] = 1;
        } else { // query
            int l, r;
            std::cin>>l>>r;
            L[i] = l;
            R[i] = r;
            mp[l] = 1;
            mp[r] = 1;
        }
    }
    for(auto &it : mp) {
        it.second = ++ptr;
    }
    for(int i = 0; i < q; i++) {
        if(T[i] == 1) {
            L[i] = mp[L[i]];
        } else {
            L[i] = mp[L[i]];
            R[i] = mp[R[i]];
        }
    }

    return 0;
}
