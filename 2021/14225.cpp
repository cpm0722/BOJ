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
vector<int> num(20, 0);
set<int> res;

void go(int idx, int sum)
{
  if (idx == n)
    res.insert(sum);
  else {
    go(idx + 1, sum + num[idx]);
    go(idx + 1, sum);
  }
  return;
}

int main(void)
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> num[i];
  res.insert(0);
  go(0, 0);
  int check = 0;
  for (auto &i : res)
  {
    if (i != check)
      break;
    check++;
  }
  cout << check << endl;
  return 0;
}
