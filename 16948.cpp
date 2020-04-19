#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};

int dis[200][200];

int x1, y1, x2, y2;

bool isIn(pair<int,int> pos){ return pos.first >= 0 && pos.first < N && pos.second >= 0 && pos.second < N; }

int bfs(void)
{
	queue<pair<int,int>>q;
	q.push(make_pair(x1, y1));
	dis[x1][y1] = 0;
	while(!q.empty()){
		pair<int,int>now = q.front(); q.pop();
		if(now.first == x2 && now.second == y2)
			break;
		for(int i = 0; i < 6; i++){
			pair<int,int>next = make_pair(now.first + dx[i], now.second + dy[i]);
			if(!isIn(next) || dis[next.first][next.second] != -1)
				continue;
			dis[next.first][next.second] = dis[now.first][now.second] + 1;
			q.push(next);
		}	
	}
	return dis[x2][y2];
}

int main(void)
{
	cin >> N;
	cin >> x1 >> y1 >> x2 >> y2;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			dis[i][j] = -1;
	cout << bfs() << endl;
	return 0;
}
