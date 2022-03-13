// https://www.hackerrank.com/challenges/digits-square-board-1/problem
#include<bits/stdc++.h>
const int N = 30;
int a[N][N];
int memo[N][N][N][N];
int mp[N][N][N][N];
bool everything_prime(int x1, int y1, int x2, int y2) {
    if(mp[x1][y1][x2][y2] != -1) return mp[x1][y1][x2][y2];
    for(int i = x1; i <= x2; i++) {
        for(int j = y1; j <= y2; j++) {
            if(!(a[i][j] == 2 or a[i][j] == 3 or a[i][j] == 5 or a[i][j] == 7)) {
                return false;
            }
        }
    }
    return mp[x1][y1][x2][y2] = true;
}
int grundy(int x1, int y1, int x2, int y2) {
    if(x1==x2 and y1==y2) return 0;
    if(everything_prime(x1,y1,x2,y2)) return 0;
    if(memo[x1][y1][x2][y2] != -1) return memo[x1][y1][x2][y2];
    //std::set<int> s;
    long long int s = 0;
    // horizontal division
    for(int i = x1; i < x2; i++) {
        int g1 = grundy(x1, y1, i, y2);
        int g2 = grundy(i+1, y1, x2, y2);
        int g = (g1^g2);
        s = (s | (1<<g));
    }
    for(int i = y1; i < y2; i++) {
        int g1 = grundy(x1, y1, x2, i);
        int g2 = grundy(x1, i+1, x2, y2);
        int g = (g1^g2);
        s = (s | (1<<g));
    }
    int mex = 0;
    for(int i = 0; ; i++) {
        if(((s>>i) & 1)==0) {
            mex = i;
            break;
        }
    }
    return memo[x1][y1][x2][y2] = mex;
}
int main() {
    
    int t;
    std::cin>>t;
    while(t--) {
        std::memset(memo, -1, sizeof memo);
        std::memset(mp, -1, sizeof mp);
        int n;
        std::cin>>n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                std::cin>>a[i][j];
            }
        }
        int g = grundy(0,0, n-1, n-1);
        if(g) {
            std::cout<<"First\n";
        } else {
            std::cout<<"Second\n";
        }
    }
}