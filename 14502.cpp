#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int map[8][8];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isIn(int x, int y){ return x >= 0 && x < N && y >= 0 && y < M; }

int bfs(void)
{
	queue<pair<int,int>>q;
	int copy_map[8][8];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			copy_map[i][j] = map[i][j];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(copy_map[i][j] == 2)
				q.push(make_pair(i, j));
	while(!q.empty()){
		pair<int,int> now = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if(isIn(nx, ny) && copy_map[nx][ny] == 0){
				copy_map[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int result = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(copy_map[i][j] == 0)
				result++;
	return result;
}

int main(void)
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin>> map[i][j];
	int result = INT32_MIN;
	for(int x1 = 0; x1 < N; x1++){
		for(int y1 = 0; y1 < M; y1++){
			if(map[x1][y1] != 0) continue;
			for(int x2 = 0; x2 < N; x2++){
				for(int y2 = 0; y2 < M; y2++){
					if(map[x2][y2] != 0) continue;
					for(int x3 = 0; x3 < N; x3++){
						for(int y3 = 0; y3 < M; y3++){
							if(map[x3][y3] != 0) continue;
							if(x1 == x2 && y1 == y2) continue;
							if(x1 == x3 && y1 == y3) continue;
							if(x2 == x3 && y2 == y3) continue;
							map[x1][y1] = 1;
							map[x2][y2] = 1;
							map[x3][y3] = 1;
							int tmp = bfs();
							if(tmp > result)
								result = tmp;
							map[x1][y1] = 0;
							map[x2][y2] = 0;
							map[x3][y3] = 0;
						}
					}
				}
			}
		}
	}
	cout << result << endl;
	return 0;
}
