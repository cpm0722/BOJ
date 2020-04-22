#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

int N;
int map[100][100];
int nonBlind[100][100];
int blind[100][100];
int nonBlindCnt = 0;
int blindCnt = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isIn(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }

void bfs(int x, int y, bool isBlind)
{
	queue<pair<int,int>> q;
	int *nowCnt;
	if(isBlind)
		nowCnt = &blindCnt;
	else
		nowCnt = &nonBlindCnt;
	q.push(make_pair(x,y));
	if(isBlind)
		blind[x][y] = ++(*nowCnt);
	else
		nonBlind[x][y] = ++(*nowCnt);
	while(!q.empty()){
		int nowX, nowY;
		tie(nowX,nowY) = q.front(); q.pop();
		for(int k = 0; k < 4; k++){
			int nx = nowX + dx[k];
			int ny = nowY + dy[k];
			if(!isIn(nx,ny)) continue;
			if(isBlind && blind[nx][ny] != -1) continue;
			if(!isBlind && nonBlind[nx][ny] != -1) continue;
			if(map[nx][ny] == map[nowX][nowY]){
				q.push(make_pair(nx, ny));
				if(isBlind)
					blind[nx][ny] = blind[nowX][nowY];
				else
					nonBlind[nx][ny] = nonBlind[nowX][nowY];
			}
			else if(isBlind){
				if((map[nowX][nowY] == 'R' && map[nx][ny] == 'G') || (map[nowX][nowY] == 'G' && map[nx][ny] == 'R')){
					q.push(make_pair(nx, ny));
					if(isBlind)
						blind[nx][ny] = blind[nowX][nowY];
					else
						nonBlind[nx][ny] = nonBlind[nowX][nowY];
				}
			}
		}
	}
	return;
}

pair<int,int> go(void)
{
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(nonBlind[i][j] == -1)
				bfs(i, j, false);
			if(blind[i][j] == -1)
				bfs(i, j, true);
		}
	}
	return make_pair(nonBlindCnt, blindCnt);
}

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++){
		string tmp;
		cin >> tmp;
		for(int j = 0; j < N; j++){
			map[i][j] = tmp[j];
			nonBlind[i][j] = -1;
			blind[i][j] = -1;
		}
	}
	
	pair<int, int>res = go();
	cout << res.first << ' ' << res.second << endl;
	return 0;
}
