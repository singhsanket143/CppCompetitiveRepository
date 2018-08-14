#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"
using namespace std;
int main(int argc, char* argv[])
{
    int tCases;
    cin>>tCases;
    char mat[55][55];
    while(tCases--) {
        int m, n, k;
        cin>>m>>n>>k;
        vector<int> bulblit(m, 0);
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) {
                cin>>mat[r][c];
                if(mat[r][c]=='*') ++bulblit[r];
            }
        }
        sort(bulblit.begin(), bulblit.end(), less<int>());
        int idx = 0;
        while(k and idx<m and n-bulblit[idx]>bulblit[idx]) {
            bulblit[idx] = n-bulblit[idx];
            k--;
            idx++;
        }
        if(k!=0 and k%2==1){
            auto it = min_element(bulblit.begin(), bulblit.end());
            *it = n - *it;
        }
        cout<<accumulate(bulblit.begin(), bulblit.end(), 0)<<'\n';
    }

    return 0;
}
