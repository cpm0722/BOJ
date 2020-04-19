#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int N;
vector<int> num;
vector<int> op(4);

pair<int,int> go(int pos, int val)
{
	if(pos == N)
		return make_pair(val, val);
	pair<int,int>result = make_pair(INT32_MIN, INT32_MAX);
	if(op[0] > 0){
		op[0]--;
		pair<int,int>tmp = go(pos + 1, val + num[pos]);
		op[0]++;
		if(result.first < tmp.first)
			result.first = tmp.first;
		if(result.second > tmp.second)
			result.second = tmp.second;
	}
	if(op[1] > 0){
		op[1]--;
		pair<int,int>tmp = go(pos + 1, val - num[pos]);
		op[1]++;
		if(result.first < tmp.first)
			result.first = tmp.first;
		if(result.second > tmp.second)
			result.second = tmp.second;
	}
	if(op[2] > 0){
		op[2]--;
		pair<int,int>tmp = go(pos + 1, val * num[pos]);
		op[2]++;
		if(result.first < tmp.first)
			result.first = tmp.first;
		if(result.second > tmp.second)
			result.second = tmp.second;
	}
	if(op[3] > 0 && num[pos] != 0){
		op[3]--;
		pair<int,int>tmp = go(pos + 1, val / num[pos]);
		op[3]++;
		if(result.first < tmp.first)
			result.first = tmp.first;
		if(result.second > tmp.second)
			result.second = tmp.second;
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
	pair<int,int>result = go(1, num[0]);
	cout << result.first << endl << result.second << endl;
	return 0;
}
