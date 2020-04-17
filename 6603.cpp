#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

static int i = 0;

void go(vector<int> num, vector<bool> b, int pos, int cnt)
{
//	cout << ++i << " Called! cnt: " << cnt << endl;
	if(cnt == 6){
		for(int i = 0; i < num.size(); i++)
			if(b[i])
				cout << num[i] << ' ';
		cout << endl;
		return;
	}
	if(pos < num.size()){
		b[pos] = true;
		go(num, b, pos + 1, cnt + 1);
		b[pos] = false;
		go(num, b, pos + 1, cnt);
	}
	return;
}

int main(void)
{
	vector<vector<int>> v;
	while(1){
		int k;
		cin >> k;
		if(k == 0)
			break;
		vector<int>num(k);
		for(int i = 0; i < k; i++)
			cin >> num[i];
		sort(num.begin(), num.end());
		v.push_back(num);
	}
	for(auto &i : v){
		vector<bool>b(i.size(), false);
		go(i, b, 0, 0);
		cout << endl;
	}
	return 0;
}
