#include <iostream>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
int map[1000][1000];
int group[1000][1000];
vector<int>groupSize;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isIn(int x, int y) { return x >= 0 && x < N && y >= 0 && y < M; }

int getNearSum(int x, int y)
{
	set<int>nearGroup;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!isIn(nx, ny)) continue;
		if(map[nx][ny] == 0)
			nearGroup.insert(group[nx][ny]);
	}
	int cnt = 0;
	for(auto &i : nearGroup)
		cnt += groupSize[i];
	return (cnt + 1) % 10;
}

void makeGroup(void)
{
	int groupCnt = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			if(map[i][j] == 0 && group[i][j] == -1){
				int size = 0;
				queue<pair<int,int>> q;
				q.push(make_pair(i, j));
				group[i][j] = groupCnt;
				while(!q.empty()){
					int nowX, nowY;
					tie(nowX, nowY) = q.front(); q.pop();
					size++;
					for(int k = 0; k < 4; k++){
						int nx = nowX + dx[k];
						int ny = nowY + dy[k];
						if(!isIn(nx, ny)) continue;
						if(map[nx][ny] == 0 && group[nx][ny] == -1){
							q.push(make_pair(nx,ny));
							group[nx][ny] = groupCnt;
						}
					}
				}
				groupSize.push_back(size);
				groupCnt++;
			}
		}
	return;
}

int main(void)
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			scanf("%1d", &map[i][j]);
			group[i][j] = -1;
		}
	makeGroup();
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(map[i][j] == 1)
				printf("%d", getNearSum(i, j));
			else printf("%d", map[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
