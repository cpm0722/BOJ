#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;

typedef struct jewel {
	int m, v, w;
} jewel;

int main(void)
{
	cin >> N >> K;
	vector<jewel>obj(N+K);
	for(int i = 0; i < N; i++){
		cin>> obj[i].m >> obj[i].v;
		obj[i].w = 0;
	}
	for(int i = 0; i < K; i++){
		cin >> obj[N+i].m;
		obj[N+i].w = 1;
	}
	sort(obj.begin(), obj.end(), [](jewel u, jewel v)
	{
		return (u.m < v.m) || ((u.m == v.m) && (u.w < v.w));
	});
	long long ans = 0;
	priority_queue<int> q;
	for(auto &i : obj){
		if(i.w == 0)
			q.push(i.v);
		else 
			if(!q.empty()){
				ans += q.top(); q.pop();
			}
	}
	cout << ans << endl;
	return 0;
}
