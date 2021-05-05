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
char board[20][20] = { '\0', };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool is_in(int y, int x)
{
  return (y >= 0 && y < n && x >= 0 && x < m);
}

int go(int cnt, vector<int>coin)
{
  queue<vector<int>> q;
  q.push(coin);
  while (!q.empty()) {
    vector<int> now_coin = q.front();
    if (now_coin[4] > 10) {
      return -1;
    }
    if ((now_coin[0] == -1 && now_coin[2] != -1) ||
        (now_coin[0] != -1 && now_coin[2] == -1)) {
      return now_coin[4];
    }
    q.pop();
    for (int i = 0; i < 4; i++) {    // move
      vector<int> next_coin = now_coin;
      next_coin[4] = now_coin[4] + 1;
      for (int j = 0; j < 2; j++) {  // coin
        int ny = now_coin[j * 2 + 0] + dy[i];
        int nx = now_coin[j * 2 + 1] + dx[i];
        if (!is_in(ny, nx)) {
          next_coin[j * 2 + 0] = -1;
          next_coin[j * 2 + 1] = -1;
        }
        else if (board[ny][nx] == '#') {
          next_coin[j * 2 + 0] = now_coin[j * 2 + 0];
          next_coin[j * 2 + 1] = now_coin[j * 2 + 1];
        }
        else {
          next_coin[j * 2 + 0] = ny;
          next_coin[j * 2 + 1] = nx;
        }
      }
      q.push(next_coin);
    }
  }
  return -1;
}

int main(void)
{
  int nx = -1, ny = -1;
  int coin_idx = 0;
  vector<int> coin(5, 0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'o') {
        coin[coin_idx * 2 + 0] = i;
        coin[coin_idx * 2 + 1] = j;
        coin_idx++;
        board[i][j] = '.';
      }
    }
  }
  int cnt = go(0, coin);
  cout << cnt << endl;
  return 0;
}
