#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int>ans;
int cnt = -1;

int main(void)
{
	cin >> N;
	vector<int>list(N);
	for(int i = 0; i < N; i++)
		cin >> list[i];
	for(int i = 0; i < N; i++){
		if(ans.size() == 0){
			ans.push_back(list[i]);
			cnt++;
		}
		else{
			auto it = lower_bound(ans.begin(), ans.end(), list[i]);
			if(it == ans.end()){
				ans.push_back(list[i]);
				cnt++;
			}
			else{
				*it = list[i];
			}
		}
	}
	cout << cnt + 1 << endl;
	return 0;
}
