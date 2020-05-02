#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int m;

vector<int> num;
int d[100001];	//d[i]: i를 만들 수 있는 경우의 수

void go()
{
	d[0] = 1;	//0을 만들 수 있는 경우의 수: 1
	for(int j = 1; j <= 3; j++)	//순서 유지 위해 1~3 순서대로 탐색
		for(int i = 1; i <= m; i++)
			if(i-j >= 0)
				d[i] += d[i-j];
	return;
}

int main(void)
{
	cin >> T;
	m = -1;
	for(int i = 0; i < T; i++){
		int t;
		scanf("%d", &t);
		num.push_back(t);
		if(num[i] > m)
			m = num[i];
	}
	

	go();
	
	for(int i = 0; i < T; i++)
		printf("%d\n", d[num[i]]);
	return 0;
}
