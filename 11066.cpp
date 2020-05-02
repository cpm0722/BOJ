#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int N;
int num[500];
int d[501][501];

int go(int l, int r)
{
	if(l > r || l +1 == r)
		return 0;
	if(d[l][r] != -1)
		return d[l][r];
	int sum = 0;
	for(int i = l; i < r; i++)
		sum += num[i];
	for(int k = l + 1; k < r; k++){
		int res = go(l, k) + go(k, r);
		if(d[l][r] == -1 || d[l][r] > res)
			d[l][r] = res;
	}
	if(d[l][r] == -1)
		d[l][r]++;
	d[l][r] += sum;
	return d[l][r];
}

int main(void)
{
	cin >> T;
	for(int i = 0; i < T; i++){
		memset(d, -1, sizeof(d));
		scanf("%d", &N);
		for(int j = 0; j < N; j++)
			scanf("%d", &num[j]);

		cout << go(0, N) << endl;

	}

	return 0;
}
