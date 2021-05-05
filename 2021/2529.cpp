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

int k;
vector<char> op(9, 0);
vector<bool>flag(10, 0);
vector<int>num(10, -1);

int max_val = INT32_MIN;
int min_val = INT32_MAX;
char max_str[10] = { 0, };
char min_str[10] = { 0, };

void compare(void)
{
  int res = 0;
  int rdx = 1;
  for (int i = k; i >= 0; i--) {
    res += num[i] * rdx;
    rdx *= 10;
  }
  if (res > max_val) {
    max_val = res;
    for (int i = 0; i <= k; i++)
      max_str[i] = num[i] + '0';
  }
  if (res < min_val) {
    min_val = res;
    for (int i = 0; i <= k; i++)
      min_str[i] = num[i] + '0';
  }
  return;
}

void go(int idx)
{
  if (idx == k + 1)
    compare();
  else {
    for (int val = 0; val < 10; val++) {
      if (flag[val])
        continue;
      if (idx == 0) {
        num[idx] = val;
        flag[val] = 1;
        go(idx + 1);
        flag[val] = 0;
        num[idx] = -1;
      }
      else if (((op[idx - 1] == '<') && (num[idx - 1] >= val)) ||
               ((op[idx - 1] == '>') && (num[idx - 1] <= val)))
        continue;
      else {
        num[idx] = val;
        flag[val] = 1;
        go(idx + 1);
        flag[val] = 0;
        num[idx] = -1;
      }
    }
    num[idx] = -1;
  }
  return;
}

int main(void)
{
  scanf("%d", &k);
  char c;
  while ((c = getchar()) != '\n');
  for (int i = 0; i < k; i++) {
    scanf("%c", &op[i]);
    getchar();
  }
  go(0);
  for (int i = 0; i <= k; i++)
    printf("%c", max_str[i]);
  printf("\n");
  for (int i = 0; i <= k; i++)
    printf("%c", min_str[i]);
  printf("\n");
  return 0;
}
