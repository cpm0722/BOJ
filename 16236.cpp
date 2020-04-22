#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int N;

int map[20][20];
vector<pair<int,int>> fish[7];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool isIn(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }
bool canMove(int x, int y, int size, int dis[20][20]){ return map[x][y] <= size && dis[x][y]==-1; }
bool canEat(int x, int y, int size){ return map[x][y] != 0 ? map[x][y] < size : false; }

int go(int x, int y)
{
	int ans = 0;
	int exp = 0;
	int size = 2;
	int nowX = x, nowY = y;
	int result = -1;
	while(true){
		queue<pair<int,int>>q;
		q.push(make_pair(nowX,nowY));
		int dis[20][20];
		for(int i = 0 ; i < N; i++)
			for(int j = 0; j < N; j++)
				dis[i][j] = -1;
		dis[nowX][nowY] = 0;
		vector<tuple<int,int,int>>dstList;
		while(!q.empty()){
			tie(nowX, nowY) = q.front(); q.pop();
			if(canEat(nowX, nowY, size))
				dstList.push_back(make_tuple(dis[nowX][nowY],nowX,nowY));
			for(int k = 0; k < 4; k++){
				int nx = nowX + dx[k];
				int ny = nowY + dy[k];
				if(!isIn(nx,ny)) continue;
				if(!canMove(nx,ny, size, dis)) continue;
				dis[nx][ny] = dis[nowX][nowY]+1;
				q.push(make_pair(nx, ny));
			}
		}
		if(dstList.size() == 0)
			break;
		sort(dstList.begin(), dstList.end());
		tie(result, nowX, nowY) = dstList[0];
		if(result == -1)
			break;
		ans += result;
		map[nowX][nowY] = 0;
		if(++exp == size){
			++size;
			exp = 0;
		}
	}
	return ans;
}

int main(void)
{
	cin >> N;
	int x, y;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			cin >> map[i][j];
			if(map[i][j] == 9){
				x = i;
				y = j;
				map[i][j] = 0;
			}
			else if(map[i][j] != 0)
				fish[map[i][j]].push_back(make_pair(i,j));
		}
	for(int i = 1; i <= 6; i++)
		sort(fish[i].begin(), fish[i].end());
	cout << go(x, y) << endl;
	return 0;
}
