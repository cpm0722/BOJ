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
int s = 0;
vector<int> num(20, 0);
vector<bool> flag(20, 0);
int ans = 0;

void go(int idx, int sum)
{
  if (idx == n) {
    if (sum == s) {
      ans++;
    }
    return;
  }
  else if (idx < n) {
    flag[idx] = 1;
    go(idx + 1, sum + num[idx]);
    flag[idx] = 0;
    go(idx + 1, sum);
  }
  return;
}

int main(void)
{
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  go(0, 0);
  if (s == 0) {
    ans--;
  }
  cout << ans << endl;
  return 0;
}
