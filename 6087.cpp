#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

int W, H;

char map[100][100];
int dis[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isIn(int x, int y) { return x >= 0 && x < H && y >= 0 && y < W; }

bool isOk(int x, int y) { return map[x][y] != '*'; }

int go(int x1, int y1, int x2, int y2)
{
	int ans = -1;
	queue<pair<int,int>> q;
	q.push(make_pair(x1, y1));
	dis[x1][y1] = -1;
	bool find = false;
	while(!q.empty()){
		int nowX, nowY;
		tie(nowX, nowY) = q.front(); q.pop();
		if(nowX == x2 && nowY == y2)
			break;
		for(int k = 0; k < 4; k++){
			int nx = nowX;
			int ny = nowY;
			while(isIn(nx+dx[k], ny+dy[k]) && isOk(nx+dx[k], ny+dy[k])){
				nx += dx[k];
				ny += dy[k];
				if(dis[nx][ny] != -2) continue;
				q.push(make_pair(nx, ny));
				dis[nx][ny] = dis[nowX][nowY] + 1;
				if(nx == x2 && ny == y2){
					find = true;
					dis[nx][ny] = dis[nowX][nowY] + 1;
					break;
				}
			}
			if(find){
				break;
			}
			nx -= dx[k];
			ny -= dy[k];
		}
		if(find)
			break;
	}
	ans = dis[x2][y2];
	return ans;
}

int main(void)
{
	cin >> W >> H;
	int x1, y1, x2, y2;
	int cnt = 0;
	for(int i = 0; i < H; i++){
		string tmp;
		cin >> tmp;
		for(int j = 0; j < W; j++){
			dis[i][j] = -2;
			map[i][j] = tmp[j];
			if(tmp[j] == 'C'){
				if(cnt == 0){
					x1 = i;
					y1 = j;
					cnt++;
				}
				else{
					x2 = i;
					y2 = j;
				}
			}
		}
	}
	cout << go(x1, y1, x2, y2) << endl;
	return 0;
}
