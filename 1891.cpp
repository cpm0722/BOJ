#include <iostream>
#include <cmath>
#include <tuple>
#include <algorithm>

using namespace std;

int d;

long long n;

string num;

string ans;

long long x, y;

bool isIn(long long x, long long y) { return x >= 0 && x < n && y >= 0 && y < n; }

pair<long long, long long> go(int index, long long r, long long c, long long size)
{
	if(size == 1 || index == d)
		return make_pair(r, c);
	if(num[index] == '2'){
		tie(r, c) = go(index+1, r, c, size/(2LL));
	}
	else if(num[index] == '1'){
		tie(r, c) = go(index+1, r, c + size/(2LL), size/(2LL));
	}
	else if(num[index] == '3'){
		tie(r, c) = go(index+1, r + size/(2LL), c, size/(2LL));
	}
	else if(num[index] == '4'){
		tie(r, c) = go(index+1, r + size/(2LL), c + size/(2LL), size/(2LL));
	}
	return make_pair(r, c);
}

void back(long long r, long long c, long long size)
{
	if(size == 1){
		return;
	}
	if(x < r + size/2){
		if(y < c + size/(2LL)){
			ans.push_back('2');
			back(r, c, size / (2LL));
		}
		else{
			ans.push_back('1');
			back(r + size/(2LL), c, size / (2LL));
		}
	}
	else {
		if(y < c + size/(2LL)){
			ans.push_back('3');
			back(r, c + size/(2LL), size / (2LL));
		}
		else{
			ans.push_back('4');
			back(r + size/(2LL), c + size/(2LL), size / (2LL));
		}
	}
	return;
}

int main(void)
{
	cin >> d;
	cin >> num;
	n = 1 << d;
	long long right, up;
	cin >> right >> up;

	tie(x,y) = go(0, 0, 0, n);

	y += right;
	x -= up;
	if(!isIn(x, y)) {
		printf("-n");
		return 0;
	}

	back(0, 0, n);

	ans.push_back('\0');

	cout << ans << endl;
	
	return 0;
}
