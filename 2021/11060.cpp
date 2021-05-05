#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int board[1001];
int save[1001];

void dp(int now)
{
  for(int i = 1; i <= board[now]; i++) {
    if (now + i <= n)
      if (save[now + i] == -1 || save[now + i] > save[now] + 1) {
        save[now + i] = save[now] + 1;
        dp(now + i);
      }
  }
  return;
}

int main(void)
{
  memset(board, -1, sizeof(board));
  memset(save, -1, sizeof(save));
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> board[i];
  save[1] = 0;
  dp(1);
  cout << save[n] << endl;
  return 0;
}
