#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;

int main(void)
{
	string str;
	cin >> str;
	N = str.size();
	vector<int> num(N);
	long long sum = 0;
	for(int i = 0; i < N; i++){
		num[i] = str[i] - '0';
		sum += num[i];
	}
	if(sum % 3 != 0){
		cout << -1 << endl;
		return 0;
	}
	sort(num.begin(), num.end(), greater<int>());
	if(num[N-1] != 0){
		cout << -1 << endl;
		return 0;
	}
	for(auto &i : num){
		cout << i;
	}
	cout << endl;
	return 0;
}
