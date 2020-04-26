#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(void)
{
	cin >> N;
	vector<int> num(N);
	vector<bool>check(N);
	for(int i = 0; i < N; i++)
		cin >> num[i];
	sort(num.begin(), num.end());
	vector<int>tmp;
	if(N == 1){
		cout << num[0] << endl;
		return 0;
	}
	for(int i = 0; i < N - 1; i++){
		if(!check[i] && !check[i+1] && num[i] < 0 && num[i+1] < 0){
			tmp.push_back(num[i] * num[i+1]);
			check[i] = true;
			check[i+1] = true;
			i++;
		}
		else if(!check[i] && !check[i+1] && num[i] < 0 && num[i+1] == 0){
			tmp.push_back(num[i] * num[i+1]);
			check[i] = true;
			check[i+1] = true;
			i++;
		}
		else if(!check[i] && num[i] == 0 || num[i] == 1){
			tmp.push_back(num[i]);
			check[i] = true;
		}
		else if(!check[i] && !check[i+1] && num[i] < 0 && num[i+1] > 0){
			tmp.push_back(num[i]);
			check[i] = true;
		}
		else if(!check[i] && num[i] > 1)
			break;
	}
	if(!check[N-1] && num[N-1] <= 1){
		tmp.push_back(num[N-1]);
		check[N-1] = true;
	}
	for(int i = N-1; i > 0; i--){
		if(!check[i] && !check[i-1] && num[i] > 1 && num[i-1] > 1){
			tmp.push_back(num[i] * num[i-1]);
			check[i] = true;
			check[i-1] = true;
			i--;
		}
		else if(!check[i] && check[i-1]){
			tmp.push_back(num[i]);
			check[i] = true;
			break;
		}
		else break;
	}
	if(!check[0] && num[0] > 1){
		tmp.push_back(num[0]);
		check[0] = true;
	}
	int ans = 0;
	for(auto &i : tmp)
		ans += i;
	cout << ans << endl;
	return 0;
}
