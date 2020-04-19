#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int N;
vector<int>num;
vector<int>op(4);

pair<int, int> go(int pos, int val)
{
	pair<int, int>result = make_pair(INT32_MIN, INT32_MAX);
	if(pos == N)
		return make_pair(val, val);
	pair<int, int> tmp[4];
	if(op[0] > 0){
		op[0]--;
		tmp[0] = go(pos + 1, val + num[pos]);
		op[0]++;
	}
	else tmp[0] = make_pair(INT32_MIN, INT32_MAX);
	if(op[1] > 0){
		op[1]--;
		tmp[1] = go(pos + 1, val - num[pos]);
		op[1]++;
	}
	else tmp[1] = make_pair(INT32_MIN, INT32_MAX);
	if(op[2] > 0){
		op[2]--;
		tmp[2] = go(pos + 1, val * num[pos]);
		op[2]++;
	}
	else tmp[2] = make_pair(INT32_MIN, INT32_MAX);
	if((op[3] > 0) && (num[pos] != 0)){
		op[3]--;
		tmp[3] = go(pos + 1, val / num[pos]);
		op[3]++;
	}
	else tmp[3] = make_pair(INT32_MIN, INT32_MAX);
	for(int i = 0; i < 4; i++){
		if(result.first < tmp[i].first)
			result.first = tmp[i].first;
		if(result.second > tmp[i].second)
			result.second = tmp[i].second;
	}
	return result;
}

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++){
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	for(int i = 0; i < 4; i++)
		cin >> op[i];
	sort(num.begin(), num.end());
	pair<int,int>result = go(1, num[0]);
	cout << result.first << endl << result.second << endl;
	
	return 0;
}
