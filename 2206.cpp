#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;
string map[1000];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isIn(int x, int y) { return x >= 0 && x < N && y >= 0 && y < M; }

int bfs(int x1, int y1, int x2, int y2)
{
	//dis[x][y][z] : map[x][y]에 까지 도달하는 거리 (z:0 벽 안부쉈을 때, z:1 벽 부쉈을 때)
	int dis[1000][1000][2];
	for(int i = 0; i < 1000; i++)
		for(int j = 0; j < 1000; j++)
			dis[i][j][0] = dis[i][j][1] = -1;
	queue<tuple<int,int,int>>q;
	q.push(make_tuple(x1, y1, 0));
	dis[x1][y1][0] = 1;
	while(!q.empty()){
		int nowX, nowY, brokenWall;
		tie(nowX, nowY, brokenWall) = q.front(); q.pop();
		//printf("%d, %d, %d : %c, %d\n", nowX, nowY, brokenWall, map[nowX][nowY], dis[nowX][nowY][brokenWall]);
		for(int i = 0; i < 4; i++){
			int nx = nowX + dx[i];
			int ny = nowY + dy[i];
			if(isIn(nx, ny)){
				//map에서 빈 칸이면
				if(map[nx][ny] == '0'){
					//이동하려는 칸에 방문한 적이 없을 때
					if(dis[nx][ny][brokenWall] == -1){
						dis[nx][ny][brokenWall] = dis[nowX][nowY][brokenWall] + 1;
						q.push(make_tuple(nx, ny, brokenWall));
					}
				}
				//map에서 벽이면
				else if(map[nx][ny] == '1'){
					//지금까지 벽을 안부쉈을 때
					if(brokenWall == 0){
					//이동하려는 칸에 방문한 적이 없을 때
						if(dis[nx][ny][1] == -1){
							dis[nx][ny][1] = dis[nowX][nowY][brokenWall] + 1;
							q.push(make_tuple(nx, ny, 1));
						}
					}
				}
			}
		}
	}
	int answer = -1;
	if(dis[x2][y2][0] != -1 && dis[x2][y2][1] != -1)
		answer = min(dis[x2][y2][0], dis[x2][y2][1]);
	else if(dis[x2][y2][0] == -1 && dis[x2][y2][1] == -1)
		answer = -1;
	else if(dis[x2][y2][0] == -1)
		answer = dis[x2][y2][1];
	else if(dis[x2][y2][1] == -1)
		answer = dis[x2][y2][0];
	return answer;
}


int main(void)
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> map[i];
	cout << bfs(0, 0, N-1, M-1) << endl;
	return 0;
}
