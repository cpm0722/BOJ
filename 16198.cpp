#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> num(10);

int go(int sum, int cnt)
{
	if(cnt == 2)
		return sum;
	int answer = INT32_MIN;
	for(int i = 1; i < cnt - 1; i++){
		int tmp = num[i];
		int val = num[i-1] * num[i+1];
		num.erase(num.begin()+i, num.begin()+(i+1));
		int res = go(sum + val, cnt-1);
		if(answer < res)
			answer = res;
		num.insert(num.begin()+i, tmp);
	}
	return answer;
}

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> num[i];
	cout << go(0, N) << endl;
	return 0;
}
