#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

char board[8][8];
bool check[8][8][10];

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

bool isIn(int x, int y) { return x >= 0 && x < 8 && y >= 0 && y < 8; }

bool isOK(int x, int y, int t){
	int tmp = min(t, 8);
	if(x-tmp < 0) return true;
	if(board[x-tmp][y] == '#') return false;
	if(x-tmp-1 < 0) return true;
	if(board[x-tmp-1][y] == '#') return false;
	return true;
}

int bfs(int x1, int y1, int x2, int y2)
{
	int ans = 0;
	queue<tuple<int,int,int>>q;
	q.push(make_tuple(x1,y1,0));
	while(!q.empty()){
		int nowX, nowY, nowT;
		tie(nowX,nowY,nowT) = q.front(); q.pop();
		if(nowX == x2 && nowY == y2){
			ans = 1;
			break;
		}
		for(int k = 0; k < 8; k++){
			int nx = nowX + dx[k];
			int ny = nowY + dy[k];
			int nt = min(nowT + 1, 8);
			if(!isIn(nx, ny)) continue;
			if(!check[nx][ny][nt]){
				if(!isOK(nx,ny,nt-1)) continue;
				check[nx][ny][nt] = true;
				q.push(make_tuple(nx, ny, nt));
			}
		}
		if(!check[nowX][nowY][min(nowT+1,8)])
			if(isOK(nowX,nowY,min(nowT,8))){
				check[nowX][nowY][min(nowT+1,8)] = true;
				q.push(make_tuple(nowX,nowY,min(nowT+1,8)));
			}
	}
	return ans;
}

int main(void)
{
	for(int i = 0; i < 8; i++){
		string str;
		cin >> str;
		for(int j = 0; j < 8; j++){
			board[i][j] = str[j];
			for(int t = 0; t < 10; t++)
				check[i][j][t] = false;
		}
	}
	cout << bfs(7, 0, 0, 7) << endl;
	return 0;
}
