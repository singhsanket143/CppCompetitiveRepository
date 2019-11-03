#include <iostream>
using namespace std;

class Solution
{
public:
  int findJudge(int N, vector<vector<int>> &trust)
  {
    int **adj = new int *[N];
    for (int i = 0; i < N; i++)
    {
      adj[i] = new int[N]();
    }

    for (int i = 0; i < trust.size(); i++)
    {
      adj[trust[i][0] - 1][trust[i][1] - 1] = 1;
    }
    int cand = -1;
    for (int i = 0; i < N; i++)
    {
      bool check = false;
      for (int j = 0; j < N; j++)
      {
        if (adj[i][j] != 0)
        {
          check = true;
          break;
        }
      }
      if (!check)
      {
        bool check2 = true;
        for (int j = 0; j < N; j++)
        {
          if (j != i and adj[j][i] != 1)
          {
            check2 = false;
            break;
          }
        }
        if (check2)
          return i + 1;
      }
    }
    return -1;
  }
};