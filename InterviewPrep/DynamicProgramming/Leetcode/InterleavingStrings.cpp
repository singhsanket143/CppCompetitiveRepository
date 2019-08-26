#include<iostream>
using namespace std;
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size(), m = s2.size();
        if (s3.size() != (n + m))
            return false;
        bool **dp = new bool *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new bool[m + 1]();
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {

                if (i == 0 and j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1] and (s2[j - 1] == s3[j - 1]);
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] and (s1[i - 1] == s3[i - 1]);
                }
                else
                {
                    dp[i][j] = (dp[i][j - 1] and (s2[j - 1] == s3[i + j - 1])) or (dp[i - 1][j] and (s1[i - 1] == s3[i + j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
