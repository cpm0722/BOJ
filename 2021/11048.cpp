#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

int n = 0;
int m = 0;
int board[1001][1001] = { 0, };
int save[1001][1001] = { 0, };

int dp(int r, int c)
{
  if (r == 0 || c == 0)
    return 0;
  else if (save[r][c] != -1)
    return save[r][c];
  save[r][c] = max(dp(r - 1, c), dp(r, c - 1)) + board[r][c];
  return save[r][c];
}

int main(void)
{
  memset(board, 0, sizeof(board));
  memset(save, -1, sizeof(save));
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> board[i][j];
  save[1][1] = board[1][1];
  int res = dp(n, m);
  cout << res << endl;
  return 0;
}
