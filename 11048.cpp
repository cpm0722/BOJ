#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int map[1000][1000];
int d[1000][1000];	//d[i][j]: map[i][j]에에 올 때까지 가져온 최대 사탕 개수

int isIn(int x, int y) { return x >= 0 && x < N && y >= 0 && y < M; }

int go(int x, int y)
{
	if(!isIn(x,y)) return 0;
	if(d[x][y] != -1)
		return d[x][y];
	d[x][y] = max(go(x-1,y), go(x,y-1)) + map[x][y];
	return d[x][y];
}

int main(void)
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			scanf("%d", &map[i][j]);
			d[i][j] = -1;
		}

	d[0][0] = map[0][0];

	cout << go(N-1, M-1) << endl;

	return 0;
}
