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

int k = 0;
int s[13] = {0, };
bool flag[13] = { 0, };

void go(int idx, int cnt)
{
  if (cnt == 6) {
    for (int i = 0; i < 13; i++)
      if (flag[i])
        cout << s[i] << ' ';
    cout << endl;
  }
  else if (idx == k)
    return;
  else {
    flag[idx] = 1;
    go(idx + 1, cnt + 1);
    flag[idx] = 0;
    go(idx + 1, cnt);
  }
  return;
}

int main(void)
{
  while (1) {
    cin >> k;
    if (k == 0)
      break;
    for (int i = 0; i < k; i++)
      cin >> s[i];
    go(0, 0);
    cout << endl;
  }
  return 0;
}
