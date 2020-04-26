#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
pair<int,int>list[10000];

int main(void)
{
	cin >> N;
	int maxDay = -1;
	for(int i = 0; i < N; i++){
		cin >> list[i].first >> list[i].second;
		if(list[i].second > maxDay)
			maxDay = list[i].second;
	}

	//날짜 기준 비오름차순 정렬
	sort(list, &list[N], [](pair<int,int>a, pair<int,int>b)
	{return a.second > b.second;});

	long long ans = 0;

	int d = maxDay;
	int i = 0;
	priority_queue<pair<int,int>>q;
	//현재 날짜를 감소시키면서 찾기
	for(int d = maxDay; d > 0; d--){
		//현재 날짜에 수행 가능한 것들(날짜가 크거나 같은 것들)을 모두 queue에 삽입
		while(i < N && list[i].second == d){
			q.push(list[i]);
			i++;
		}
		if(!q.empty()){
			//가장 가치가 높은 것 하나 뽑아 더하기
			ans += q.top().first;
			q.pop();
		}
	}

	cout << ans << endl;
	return 0;
}
