#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, K;
int W[100];
int V[100];
int d[101][100001];	//d[i][j]: i번째 물건까지 고려했을 때 최대 무게가 j인 상태에서의 가치 최댓값

int go()
{
	for(int i = 0; i < N; i++)
		d[i][W[i]] = V[i];
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j <= K; j++){
			if(d[i][j] == -1) continue;
			if(j+W[i+1] <= K){
				if(d[i+1][j+W[i+1]] == -1 || d[i+1][j+W[i+1]] < d[i][j] + V[i+1])
					d[i+1][j+W[i+1]] = d[i][j] + V[i+1];
			}
			if(d[i+1][j] == -1 || d[i+1][j] < d[i][j])
				d[i+1][j] = d[i][j];
		}
	}
	int res = 0;
	for(int i = 0; i < N; i++){
		for(int j = K; j >= 0; j--){
			if(d[i][j] == -1) continue;
			if(d[i][j] > res)
				res = d[i][j];
		}
	}
	
	return res;
}

int main(void)
{
	memset(d, -1, sizeof(d));
	cin >> N >> K;
	for(int i = 0; i < N; i++)
		scanf("%d%d", &W[i], &V[i]);
	cout << go() << endl;
	return 0;
}
