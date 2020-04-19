#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T;

vector<pair<int, int>> list;
int dist[10000], from[10000];
char how[10000];

void dfs(pair<int, int>val)
{
	for(int i = 0; i < 10000; i++){
		dist[i] = 0;
		from[i] = 0;
		how[i] = ' ';
	}
	int src = val.first, dst = val.second;
	dist[src] = 0; from[src] = -1; how[src] = ' ';
	queue<int> q;
	q.push(src);
	int now;
	while(!q.empty()){
		now = q.front(); q.pop();
		if(now == dst)
			break;
		int D = (now * 2) % 10000;
		int S; now==0 ? S = 9999 : S = now-1;
		int L = (now / 1000) + (now % 1000) * 10;
		int R = (now % 10) * 1000 + (now / 10);
		if(dist[D] == 0){
			dist[D] = dist[now] + 1;
			from[D] = now;
			how[D] = 'D';
			q.push(D);
		}
		if(dist[S] == 0){
			dist[S] = dist[now] + 1;
			from[S] = now;
			how[S] = 'S';
			q.push(S);
		}
		if(dist[L] == 0){
			dist[L] = dist[now] + 1;
			from[L] = now;
			how[L] = 'L';
			q.push(L);
		}
		if(dist[R] == 0){
			dist[R] = dist[now] + 1;
			from[R] = now;
			how[R] = 'R';
			q.push(R);
		}
	}
	if(now == dst){
		vector<char>print;
		while(now != src){
			print.push_back(how[now]);
			now = from[now];
		}
		reverse(print.begin(), print.end());
		for(auto &i : print)
			cout << i;
		cout << endl;
	}
	return;
}

int main(void)
{
	cin >> T;
	for(int i = 0; i < T; i++){
		pair<int, int>tmp;
		cin >> tmp.first >> tmp.second;
		list.push_back(tmp);
	}
	for(int i = 0; i < T; i++){
		dfs(list[i]);
	}
	return 0;
}
