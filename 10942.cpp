#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int num[2000];
pair<int,int> q[1000000];
bool d[2000][2000];

void go()
{
	for(int i = 0; i < N-1; i++){
		d[i][i] = true;
		if(num[i] == num[i+1])
			d[i][i+1] = true;
	}
	d[N-1][N-1] = true;
	for(int i = N-1; i >= 0; i--){
		for(int j = i+2; j < N; j++){
			if(d[i+1][j-1] && (num[i] == num[j]))
				d[i][j] = true;
			else
				d[i][j] = false;
		}
	}

	return;
}

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	cin >> M;
	for(int i = 0; i < M; i++)
		scanf("%d%d", &q[i].first, &q[i].second);

	go();

	for(int i = 0; i < M; i++)
		printf("%d\n", (int)d[q[i].first-1][q[i].second-1]);
		
	return 0;
}
