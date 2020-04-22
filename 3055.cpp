#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int R, C;

int map[52][52];

bool isIn(int x, int y) { return x >= 0 && x < R && y >= 0 && y < C; }

//t시간에 x,y로 이동할 수 있는지 판단
bool isOK(int x, int y, int t) {
	switch(map[x][y]){
		case -4:
			return false;
		case -3:
		case -2:
			return true;
		case -1:
			return false;
		default:
			return map[x][y] > t + 1;
	}
}

int go(int x1, int y1, int x2, int y2)
{
	int ans = INT32_MAX;
	queue<tuple<int,int,int>>q;
	q.push(make_tuple(x1,y1,0));
	while(!q.empty()){
		int nowX, nowY, nowT;
		tie(nowX, nowY, nowT) = q.front(); q.pop();
		if(nowX == x2 && nowY == y2){
			if(ans > nowT)
				ans = nowT;
		}
		for(int k = 0; k < 4; k++){
			int nx = nowX + dx[k];
			int ny = nowY + dy[k];
			if(!isIn(nx,ny)) continue;
			if(isOK(nx, ny, nowT)){
				map[nx][ny] = -4;
				q.push(make_tuple(nx, ny, nowT+1));
			}
		}
	}
	return ans == INT32_MAX ? -1 : ans;
}

void make_t_map(void)
{
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(map[i][j] == 0){
				queue<pair<int,int>>q;
				q.push(make_pair(i,j));
				while(!q.empty()){
					int nowX, nowY;
					tie(nowX, nowY) = q.front(); q.pop();
					for(int k = 0; k < 4; k++){
						int nx = nowX + dx[k];
						int ny = nowY + dy[k];
						if(!isIn(nx, ny)) continue;
						if((map[nx][ny] == -3) || (map[nx][ny] > map[nowX][nowY]+1)){
							map[nx][ny] = map[nowX][nowY] + 1;
							q.push(make_pair(nx,ny));
						}
					}
				}
			}
		}
	}
	return;
}

int main(void)
{
	cin >> R >> C;
	int x1, y1, x2, y2;
	for(int i = 0; i < R; i++){
		string tmp;
		cin >> tmp;
		for(int j = 0; j < C; j++){
			map[i][j] = tmp[j];
			switch(map[i][j]){
				case 'S':
					x1 = i;
					y1 = j;
					map[i][j] = -3;
					break;
				case 'D':
					x2 = i;
					y2 = j;
					map[i][j] = -2;
					break;
				case 'X':
					map[i][j] = -1;
					break;
				case '.':
					map[i][j] = -3;
					break;
				case '*':
					map[i][j] = 0;
					break;
			}
		}
	}
	make_t_map();
	int ans = go(x1, y1, x2, y2);
	if(ans == -1)
		cout << "KAKTUS" << endl;
	else cout << ans << endl;
	return 0;
}
