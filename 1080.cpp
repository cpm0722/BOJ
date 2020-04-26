#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int src[50][50];
int dst[50][50];

void change(int x, int y){
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			src[x+i][y+j] = 1-src[x+i][y+j];
	return;
}

int main(void)
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%1d", &src[i][j]);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%1d", &dst[i][j]);
	
	int cnt = 0;
	for(int i = 0; i < N - 2; i++){
		for(int j = 0; j < M - 2; j++){
			if(src[i][j] != dst[i][j]){
				change(i, j);
				cnt++;
			}
		}
	}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(src[i][j] != dst[i][j]){
				cout << "-1" << endl;
				return 0;
			}
	cout << cnt << endl;
	return 0;
}
