#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, K;

typedef struct jewel {
	int m, v;
} jewel;

bool cmp(jewel a, jewel b)
{
	if(a.v > b.v)
		return true;
	else if(a.v < b.v)
		return false;
	else return false;
}

int main(void)
{
	cin >> N >> K;
	vector<jewel>obj(N);
	multiset<int> s;
	for(int i = 0; i < N; i++){
		cin>> obj[i].m >> obj[i].v;
	}
	for(int i = 0; i < K; i++){
		int tmp;
		cin >> tmp;
		s.insert(tmp);
	}
	sort(obj.begin(), obj.end(), cmp);
	long long ans = 0;
	for(int i = 0; i < N; i++){
		auto it = s.lower_bound(obj[i].m);
		if(it != s.end()){
			ans += obj[i].v;
			s.erase(it);
		}
	}
	cout << ans << endl;
	return 0;
}
