#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int m;

vector<int> num;
int d[3][100001];	//d[i][j]: 1~i+1까지의 수로 j를 만들 수 있는 경우의 수

void go()
{
	d[0][0] = d[1][0] = d[2][0] = 1;
	for(int i = 0; i < 3; i++){
		for(int j = 1; j <= m; j++){
			if(i == 0)
				d[i][j] = 1;
			else {
				d[i][j] = d[i-1][j];
				if(j-(i+1) >= 0)
					d[i][j] += d[i][j-(i+1)];
			}
		}
	}
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
		printf("%d\n", d[2][num[i]]);
	return 0;
}
