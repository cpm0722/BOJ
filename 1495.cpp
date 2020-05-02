#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, S, M;
int V[100];
bool d[101][1001];	//d[i][j]: i번째 곡을 j볼륨으로 연주 가능한가

int go()
{
	if(S-V[0] >= 0 && S-V[0] <= M)
		d[0][S-V[0]] = true;
	if(S+V[0] >= 0 && S+V[0] <= M)
		d[0][S+V[0]] = true;
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j <= M; j++){
			if(!d[i][j]) continue;
			if(j+V[i+1] <= M && j+V[i+1]>=0)
				d[i+1][j+V[i+1]] = true;
			if(j-V[i+1] >= 0 && j-V[i+1] <= M)
				d[i+1][j-V[i+1]] = true;
		}
	}
	int m = -1;
	for(int j = M; j >= 0; j--){
		if(d[N-1][j] && j > m){
			m = j;
			break;
		}
	}
	return m;
}

int main(void)
{
	cin >> N >> S >> M;
	for(int i = 0; i < N; i++)
		scanf("%d", &V[i]);
	memset(d, false, sizeof(d));

	cout << go() << endl;
	
	return 0;
}
