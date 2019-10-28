#include "iostream"
#include "unordered_map"
using namespace std;

int main(int argc, char const *argv[])
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    unordered_map<int, int> row, col;
    for (int i = 0; i < q; i++)
    {
      int x, y;
      scanf("%d %d", &x, &y);
      row[x - 1]++;
      col[y - 1]++;
    }
    // for(auto it = row.begin(); it != row.end(); it++) {
    //   int x = (*it).first;
    //   int val = (*it).second;
    //   for(int i = 0; i < m; i++) {
    //     arr[x][i] += val;
    //   }
    // }
    // for (auto it = col.begin(); it != col.end(); it++)
    // {
    //   int x = (*it).first;
    //   int val = (*it).second;
    //   for (int i = 0; i < n; i++)
    //   {
    //     arr[i][x] += val;
    //   }
    // }
    int ans = 0;
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < m; j++) {
    //     if (arr[i][j]&1) ans++;
    //   }
    // }
    printf("%d\n", ans);
  }
  return 0;
}
