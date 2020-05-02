#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int hp[3];
int d[61][61][61];	//d[i][j][k]: scv의 체력이 각각 i,j,k일 때 지금까지 공격한 최소 횟수

int go(int i, int j, int k)
{
	//printf("%d %d %d: %d\n", i, j, k, d[i][j][k]);
	if(i == 0 && j == 0 && k == 0)
		return d[i][j][k];
	int attack[3] = {1, 3, 9};
	int ans = INT32_MAX;
	int r = 0;
	do{
		int n_i = max(0, i-attack[0]);
		int n_j = max(0, j-attack[1]);
		int n_k = max(0, k-attack[2]);
		if(d[n_i][n_j][n_k] == -1 || d[n_i][n_j][n_k] > d[i][j][k]+1){
			d[n_i][n_j][n_k] = d[i][j][k] + 1;
			int tmp = go(n_i,n_j,n_k);
			if(tmp < ans)
				ans = tmp;
		}
	}while(next_permutation(attack, attack+3));
	return ans;
}

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> hp[i];

	memset(d, -1, sizeof(d));

	for(int i = N; i < 3; i++)
		hp[i] = 0;

	int i = hp[0], j = hp[1], k = hp[2];
	d[i][j][k] = 0;
	cout << go(i,j,k) << endl;
	
	return 0;
}
