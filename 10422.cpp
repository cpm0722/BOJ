#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
long long d[5005];	//d[i]: i개의 문자로 이루어진 문자열에서 가능한 올바른 괄호 문자열의 최대 값

int go(int len)
{
	if(len < 0) return 0;
	if(len % 2 || len <= 2) return d[len];
	long long &ans = d[len];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int k = 1; k < len; k++){	//k: 첫번째 여는 괄호에 대응하는 닫는 괄호의 위치
		ans += go(k-1) * go(len-(k+1));	//첫번째 괄호 내의 경우의 수 * 첫번째 괄호 바깥의 경우의 수
		ans %= 1000000007;
	}
	return ans;
}

int main(void)
{
	cin >> T;
	memset(d, -1, sizeof(d));
	d[0] = 1;
	d[1] = 0;
	d[2] = 1;
	for(int i = 0; i < 2502; i++)
		d[i*2+1] = 0;
	go(5000);
	for(int i = 0; i < T; i++){
		int tmp;
		scanf("%d", &tmp);
		cout << d[tmp] << endl;
	}
	return 0;
}
