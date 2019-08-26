#include "iostream"
using namespace std;
class Solution
{
public:
    bool isMatch(string A, string B)
    {
        int m = A.size(), n = B.size();
        bool **dp = new bool *[A.size() + 1];
        for (int i = 0; i <= m; i++)
        {
            dp[i] = new bool[n + 1]();
        }
        dp[0][0] = true;
        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            if (B[i - 1] == '*')
            {
                dp[0][i] = dp[0][i - 1];
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (B[j - 1] == '?' or B[j - 1] == A[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (B[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = false;
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
