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

int n = 0;

int res = 0;

bool check(int idx, int col[15])
{
  for (int i = 0; i <= idx; i++) {
    for (int j = 0; j <= idx; j++) {
      if (i == j) {
        continue;
      }
      if ((col[i] - col[j] == i - j) ||
          (col[i] - col[j] == j - i)) {
        return false;
      }
    }
  }
  return true;
}

void go(int idx, int col[15], bool flag[15])
{
  if (idx == n) {
    res++;
    return;
  }
  else {
    for (int i = 0; i < n; i++) {
      if (flag[i]) {
        continue;
      }
      flag[i] = true;
      col[idx] = i;
      if (check(idx, col)) {
        go(idx + 1, col, flag);
      }
      flag[i] = false;
    }
  }
  return;
}

int main(void)
{
  cin >> n;
  int col[15] = { 0, };
  bool flag[15] = { 0, };
  go(0, col, flag);
  cout << res << endl;
  return 0;
}
