#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> result;
int N;

void go(vector<int> num, int pos, int sum)
{
	if(pos == N){
		if(sum != 0)
			result.push_back(sum);
	}
	else {
		go(num, pos + 1, sum + num[pos]);
		go(num, pos + 1, sum);
	}
	return;
}

int main(void)
{
	cin >> N;
	vector<int>num(N);
	for(auto &i : num)
		cin >> i;
	go(num, 0, 0);
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	int i;
	for(i = 1; i <= result.size(); i++){
		if(result[i-1] != i){
			break;
		}
	}
	cout << i << endl;
	return 0;
}
