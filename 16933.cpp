#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int map[1000][1000];
int dis[1000][1000][10][2];

int dx[5] = {1, -1, 0, 0};
int dy[5] = {0, 0, 1, -1};

bool isIn(int x, int y) { return x >= 0 && x < N && y >= 0 && y < M; }

int bfs(int x1, int y1, int x2, int y2)
{
	int ans = -1;
	queue<tuple<int,int,int,int>>q;
	q.push(make_tuple(x1, y1, 0, 0));
	dis[x1][y1][0][0] = 1;
	while(!q.empty()){
		int nowX, nowY, nowK, nowDay;
		tie(nowX,nowY,nowK,nowDay) = q.front(); q.pop();
		if(nowX == x2 && nowY == y2){
			ans = dis[nowX][nowY][nowK][nowDay];
			break;
		}
		for(int k = 0; k < 4; k++){
			int nx = nowX + dx[k];
			int ny = nowY + dy[k];
			if(!isIn(nx, ny)) continue;
			if(map[nx][ny] == 0){
				if(dis[nx][ny][nowK][(nowDay+1)%2] == -1){
					dis[nx][ny][nowK][(nowDay+1)%2] = dis[nowX][nowY][nowK][nowDay] + 1;
					q.push(make_tuple(nx, ny, nowK, (nowDay+1)%2));
				}
			}
			else {
				if(nowK < K && nowDay == 0){
					if(dis[nx][ny][nowK+1][(nowDay+1)%2] == -1){
						dis[nx][ny][nowK+1][(nowDay+1)%2] = dis[nowX][nowY][nowK][nowDay] + 1;
						q.push(make_tuple(nx, ny, nowK+1, (nowDay+1)%2));
					}
				}
			}
		}
		if(dis[nowX][nowY][nowK][(nowDay+1)%2] == -1){
			dis[nowX][nowY][nowK][(nowDay+1)%2] = dis[nowX][nowY][nowK][nowDay] + 1;
			q.push(make_tuple(nowX, nowY, nowK, (nowDay+1)%2));
		}
	}
	return ans;
}

int main(void)
{
	cin >> N >> M >> K;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			for(int k = 0; k <= K; k++){
				dis[i][j][k][0] = -1;
				dis[i][j][k][1] = -1;
			}
			scanf("%1d", &map[i][j]);
		}
	cout << bfs(0, 0, N-1, M-1) << endl;
	return 0;
}
