#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int T;

bool primaryArray[10000];

void makePrimaryArray(int n)
{
	if (n <= 1) return;
	primaryArray[0] = primaryArray[1] = false;
	for (int i = 2; i <= n; i++)
		primaryArray[i] = true;
	for (int i = 2; i * 2 <= n; i++)
	{
		if (primaryArray[i])
			for (int j = i * 2; j <= n; j += i)
				primaryArray[j] = false;
	}
	return;
}

int makeNum(int num[4]) { return num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3] * 1; }

int go(int src, int dst)
{
	int ans = 0;
	queue<int> q;
	q.push(src);
	int dis[10000];
	for(int i = 0; i < 10000; i++)
		dis[i] = -1;
	dis[src] = 0;
	while(!q.empty()){
		int now = q.front(); q.pop();
		int num[4];
		num[0] = now / 1000;
		num[1] = (now - (num[0] * 1000)) / 100;
		num[2] = (now - (num[0] * 1000) - (num[1] * 100)) / 10;
		num[3] = now % 10;
		if(now == dst){
			ans = dis[now];
			break;
		}
		for(int i = 0; i < 4; i++){
			int tmp[4];
			for(int k = 0; k < 4; k++)
				tmp[k] = num[k];
			vector<int>numList;
			for(int j = 0; j <= 9; j++){
				if(j != num[i]){
					if(j != 0)
						numList.push_back(j);
					else if(i != 0)
						numList.push_back(j);
				}
			}
			for(int j = 0; j < numList.size(); j++){
				tmp[i] = numList[j];
				int tmpNum = makeNum(tmp);
				if(primaryArray[tmpNum]){
					if((dis[tmpNum] == -1) || (dis[tmpNum] > (dis[now] + 1))){
						q.push(tmpNum);
						dis[tmpNum] = dis[now] + 1;
					}
				}
			}
		}
	}
	return ans;
}

int main(void)
{
	cin >> T;
	makePrimaryArray(9999);
	vector<pair<int,int>>input;
	for(int i = 0; i < T; i++){
		pair<int,int>t;
		cin >> t.first >> t.second;
		input.push_back(t);
	}
	for(int i = 0; i < T; i++){
		int tmp = go(input[i].first, input[i].second);
		if(tmp == -1)
			cout << "Impossible" << endl;
		else cout << tmp << endl;
	}
	return 0;
}
