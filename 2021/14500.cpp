#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

int n = 0, m = 0;
int board[500][500] = { 0, };
bool flag[500][500] = { 0, };

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int max_val = INT32_MIN;

bool is_in(int r, int c)
{
  return ((r >= 0 && r < n) && (c >= 0 && c < m));
}

int blocks(int r, int c, int cnt)
{
  if (cnt == 4) {
    return 0;
  }
  int val = board[r][c];
  int res = -1;
  for (int i = 0; i < 4; i++) {
    int nx = r + dx[i];
    int ny = c + dy[i];
    if (is_in(nx, ny)) {
      if (!flag[nx][ny]) {
        flag[nx][ny] = 1;
        res = max(res, blocks(nx, ny, cnt + 1));
        flag[nx][ny] = 0;
      }
    }
  }
  if (res == -1) {
    return -1;
  }
  return val + res;
}

int special_block(int r, int c)
{
  int val = -1;
  // ***
  //  *
  if (is_in(r + 1, c + 2)){
    val = (board[r][c] +
      board[r][c + 1] +
      board[r][c + 2] +
      board[r + 1][c + 1]);
  }
  //  *
  // **
  //  *
  if (is_in(r + 2, c - 1)){
    val = max(val, board[r][c] +
      board[r + 1][c] +
      board[r + 2][c] +
      board[r + 1][c - 1]);
  }
  //   *
  //  ***
  if (is_in(r + 1, c - 1) && is_in(r + 1, c + 1)){
    val = max(val, board[r][c] +
      board[r + 1][c - 1] +
      board[r + 1][c] +
      board[r + 1][c + 1]);
  }
  //   *
  //   **
  //   *
  if (is_in(r + 2, c + 1)) {
    val = max(val, board[r][c] +
      board[r + 1][c] +
      board[r + 2][c] +
      board[r + 1][c + 1]);
  }
  return val;
}

void go(int r, int c)
{
  if (r == n) {
    return;
  }
  else {
    int val = -1;
    memset(flag, 0, sizeof(flag));
    flag[r][c] = 1;
    val = max(val, blocks(r, c, 0));
    flag[r][c] = 0;
    val = max(val, special_block(r, c));
    if (val > max_val) {
      max_val = val;
    }
    int next_r = (c == m - 1) ? r + 1 : r;
    int next_c = (c == m - 1) ? 0 : c + 1;
    go(next_r, next_c);
  }
  return;
}

int main(void)
{
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }
  go(0, 0);
  cout << max_val << endl;
  return 0;
}
