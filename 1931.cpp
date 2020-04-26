#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

int N;
pair<int,int> list[100000];

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if(a.second < b.second)
		return true;
	else if(a.second > b.second)
		return false;
	else {
		if(a.first < b.first)
			return true;
		else if(a.first > b.first)
			return false;
		else return true;
	}
}

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> list[i].first >> list[i].second;
	int cnt = 0;
	int now = 0;
	sort(list, &list[N], cmp);
	for(int i = 0; i < N; i++){
		if(now <= list[i].first){
			cnt++;
			now = list[i].second;
		}
	}
	cout << cnt << endl;
	return 0;
}
