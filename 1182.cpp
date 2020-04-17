#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;

int go(vector<int>num, int pos, int sum){
	if(pos == N){
		if(sum == S){
			return 1;
		}
		else{ 
			return 0;
		}
	}
	
	int cnt = 0;
	cnt += go(num, pos + 1, sum + num[pos]);
	cnt += go(num, pos + 1, sum);
	return cnt;
}

int main(void)
{
	cin >> N >> S;
	vector<int>num(N);
	for(auto &i : num)
		cin >> i;
	int tmp = 0;
	if(S == 0) tmp++;
	cout << go(num, 0, 0) - tmp << endl;
	return 0;
}
