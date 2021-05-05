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
int num[11] = { 0, };
int op_cnt[4] = { 0, };
char op[10] = { '\0', };
int max_val = INT32_MIN, min_val = INT32_MAX;

void go(int idx, int op_rest[4])
{
  if (idx == n - 1) {
    int res = num[0];
    for(int i = 1; i < n; i++) {
      switch(op[i - 1]) {
        case '+':
          res += num[i];
          break;
        case '-':
          res -= num[i];
          break;
        case '*':
          res *= num[i];
          break;
        case '/':
          res /= num[i];
          break;
      }
    }
    if (res > max_val) {
      max_val = res;
    }
    if (res < min_val) {
      min_val = res;
    }
    return;
  }
  else {
    const char *ops = "+-*/";
    for (int i = 0; i < 4; i++) {
      if (op_rest[i]) {
        op[idx] = ops[i];
        op_rest[i]--;
        go(idx + 1, op_rest);
        op_rest[i]++;
      }
    }
  }
  return;
}

int main(void)
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  for (int i = 0; i < 4; i++) {
    cin >> op_cnt[i];
  }
  int op_rest[4] = { 0, };
  memcpy(op_rest, op_cnt, sizeof(op_rest));
  go(0, op_rest);
  cout << max_val << endl << min_val << endl;
  return 0;
}
