#include<iostream>
using namespace std;
#define ll long long int
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        if (m > n)
            return 0;
        int **dp = new int *[m + 1];
        for (int i = 0; i <= m; i++)
        {
            dp[i] = new int[n + 1]();
        }

        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[j - 1] != t[i - 1])
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else
                {
                    ll a = dp[i][j - 1];
                    ll b = dp[i - 1][j - 1];
                    dp[i][j] = (int)(a + b);
                }
            }
        }
        return dp[m][n];
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
