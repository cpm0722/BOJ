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
int w[10] = { 0, };

int max_val = INT32_MIN;

void go(int cnt, bool flag[10], int val)
{
  if (cnt == n - 2) {
    if (val > max_val) {
      max_val = val;
    }
    return;
  }
  for (int i = 1; i < n - 1; i++) {
    if (!flag[i]) {
      int before = 0;
      for (int j = i - 1; j >= 0; j--) {
        if (!flag[j]) {
          before = w[j];
          break;
        }
      }
      int after = 0;
      for (int j = i + 1; j < n; j++) {
        if (!flag[j]) {
          after = w[j];
          break;
        }
      }
      flag[i] = true;
      go(cnt + 1, flag, val + before * after);
      flag[i] = false;
    }
  }
  return;
}

int main(void)
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  bool flag[10] = { 0, };
  go(0, flag, 0);
  cout << max_val << endl;
  return 0;
}
