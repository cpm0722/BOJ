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

bool go(int idx);

int n = 0;
int board[N][N] = { 0, };

bool domino[N + 1][N + 1] = { 0, };
bool row[N][N + 1] = { 0, };
bool col[N][N + 1] = { 0, };
bool square[N][N + 1] = { 0, };

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void preprocess(void)
{
  memset(row, 0, sizeof(row));
  memset(col, 0, sizeof(col));
  memset(square, 0, sizeof(square));
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (board[r][c]) {
        row[r][board[r][c]] = true;
        col[c][board[r][c]] = true;
        square[r / 3 * 3 + c / 3][board[r][c]] = true;
      }
    }
  }
  return;
}

bool check(int r, int c, int num)
{
  return (!row[r][num] && !col[c][num] && !square[r / 3 * 3 + c / 3][num]);
}

bool is_in(int x, int y)
{
  return (x >= 0 && x <= N && y >= 0 && y <= N);
}

bool put_domino(int idx, int r, int c, int num1, int nr, int nc, int num2)
{
  if (check(r, c, num1) && check(nr, nc, num2)) {
    domino[num1][num2] = true;
    row[r][num1] = true;
    col[c][num1] = true;
    square[r / 3 * 3 + c / 3][num1] = true;
    row[nr][num2] = true;
    col[nc][num2] = true;
    square[nr / 3 * 3 + nc / 3][num2] = true;

    board[r][c] = num1;
    board[nr][nc] = num2;

    if (go(idx + 1)) {
      return true;
    }

    board[r][c] = 0;
    board[nr][nc] = 0;

    domino[num1][num2] = false;
    row[r][num1] = false;
    col[c][num1] = false;
    square[r / 3 * 3 + c / 3][num1] = false;
    row[nr][num2] = false;
    col[nc][num2] = false;
    square[nr / 3 * 3 + nc / 3][num2] = false;
  }
  return false;
}

bool go(int idx)
{
  if (idx == N * N) {
    return true;
  }
  else {
    int r = idx / N;
    int c = idx % N;
    if (board[r][c]) {
      return go(idx + 1);
    }
    for (int i = 0; i < 4; i++) {  // move
      int nr = r + dy[i];
      int nc = c + dx[i];
      if (!is_in(nr, nc) || board[nr][nc]) {
        continue;
      }
      for (int j = 1; j < N; j++) {  // domino 1
        for (int k = j + 1; k <= N; k++) {  // domino 2
          if (domino[j][k]) {
            continue;
          }
          if (put_domino(idx, r, c, j, nr, nc, k)) {
            return true;
          }
          if (put_domino(idx, r, c, k, nr, nc, j)) {
            return true;
          }
        }
      }
    }
    return false;
  }
  return true;
}

int main(void)
{
  int cnt = 0;
  while (++cnt) {
    cin >> n;
    if (!n) {
      break;
    }
    memset(board, 0, sizeof(board));
    memset(domino, 0, sizeof(domino));
    for (int i = 0; i < n; i++) {
      int num1 = 0, num2 = 0;
      string loc1, loc2;
      cin >> num1 >> loc1 >> num2 >> loc2;
      board[loc1[0] - 'A'][loc1[1] - '1'] = num1;
      board[loc2[0] - 'A'][loc2[1] - '1'] = num2;
      domino[min(num1, num2)][max(num1, num2)] = true;
    }
    for (int i = 1; i <= N; i++) {
      string loc;
      cin >> loc;
      board[loc[0] - 'A'][loc[1] - '1'] = i;
    }
    preprocess();
    go(0);
    cout << "Puzzle " << cnt << endl;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << board[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
