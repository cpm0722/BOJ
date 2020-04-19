#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int dst[101];
int dis[101];

int bfs(void)
{
	queue<int> q;
	int pos = 1;
	q.push(pos);
	dis[pos] = 0;
	while(!q.empty()){
		pos = q.front(); q.pop();
		if(pos == 100)
			break;
		for(int i = 1; i <= 6; i++){
			if(dis[dst[pos+i]] == -1){
				q.push(dst[pos+i]);
				dis[dst[pos+i]] = dis[pos]+1;
			}
		}
	}
	return dis[100];
}

int main(void)
{
	cin >> N >> M;
	pair<int,int> lad[15];
	pair<int,int> snake[15];
	for(int i = 0; i < N; i++)
		cin >> lad[i].first >> lad[i].second;
	for(int i = 0; i < M; i++)
		cin >> snake[i].first >> snake[i].second;
	for(int i = 1; i <= 100; i++)
		dst[i] = i;
	for(auto &i : lad)
		dst[i.first] = i.second;
	for(auto &i : snake)
		dst[i.first] = i.second;
	for(auto &i : dis)
		i = -1;
	cout << bfs() << endl;
	return 0;
}
