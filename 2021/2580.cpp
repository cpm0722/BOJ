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

#define N 9

using namespace std;

int board[N][N] = { 0, };
bool row[N][N + 1] = { 0, };
bool col[N][N + 1] = { 0, };
bool square[N][N + 1] = { 0, };

bool go(int idx)
{
  if (idx == N * N) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << board[i][j] << ' ';
      }
      cout << endl;
    }
    return true;
  }
  int r = idx / N;
  int c = idx % N;
  if (board[r][c] != 0) {
    return go(idx + 1);
  }
  else {
    for (int num = 1; num <= N; num++) {  // select number
      if (!row[r][num] &&
          !col[c][num] &&
          !square[r / 3 * 3 + c / 3][num]) {
        board[r][c] = num;
        row[r][num] = true;
        col[c][num] = true;
        square[r / 3 * 3 + c / 3][num] = true;
        if(go(idx + 1)) {
          return true;
        }
        board[r][c] = 0;
        row[r][num] = false;
        col[c][num] = false;
        square[r / 3 * 3 + c / 3][num] = false;
      }
    }
  }
  return false;
}

int main(void)
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      row[i][board[i][j]] = true;
      col[j][board[i][j]] = true;
      square[i / 3 * 3 + j / 3][board[i][j]] = true;
    }
  }
  go(0);
  return 0;
}
