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

int board[101] = { 0, };
int history[101] = { 0, };

void bfs(void)
{
  queue<int> q;
  q.push(1);
  int now;
  while (!q.empty()) {
    now = q.front(); q.pop();
    if (now == 100)
      break;
    for (int i = 1; i <= 6; i++)
      if (history[board[now + i]] == -1) {
        q.push(board[now + i]);
        history[board[now + i]] = history[now] + 1;
      }
  }
  return;
}

int main(void)
{
  memset(history, -1, sizeof(history));
  history[1] = 0;
  pair<int,int> ladders[15];
  pair<int,int> snakes[15];
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> ladders[i].first >> ladders[i].second;
  for (int i = 0; i < m; i++)
    cin >> snakes[i].first >> snakes[i].second;
  for (int i = 1; i <= 100; i++)
    board[i] = i;
  for (int i = 0; i < n; i++)
    board[ladders[i].first] = ladders[i].second;
  for (int i = 0; i < m; i++)
    board[snakes[i].first] = snakes[i].second;
  bfs();
  cout << history[100] << endl;
  return 0;
}
