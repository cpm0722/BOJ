#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[500][500];
bool check[500][500];
int N, M;
int maximum = INT32_MIN;

int dx[4] = {1, -1,  0, 0};
int dy[4] = {0,  0, -1, 1};

void go(int y, int x, int sum, int cnt)
{
	if(cnt == 4){
		if(maximum < sum)
			maximum = sum;
		return;
	}
	if(!(y >= 0 && y < N && x >= 0 && x < M))
		return;
	if(check[y][x]) return;
	check[y][x] = true;
	sum = 0;
	for(int i = 0; i < 4; i++)
		go(y + dy[i], x + dx[i], sum+arr[y][x], cnt + 1);
	check[y][x] = false;
	return;
}

int main(void)
{
#ifndef DEBUG
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> arr[i][j];
#endif
#ifdef DEBUG
	N = 5; M = 5;
	for(int i = 0; i < M; i++)
		arr[0][i] = i + 1;
	for(int i = 0; i < M; i++)
		arr[1][i] = 5 - i;
	for(int i = 0; i < M; i++)
		arr[2][i] = i + 2;
	for(int i = 0; i < M; i++)
		arr[3][i] = 6 - i;
	arr[4][0] = 1;
	arr[4][1] = 2;
	arr[4][2] = 1;
	arr[4][3] = 2;
	arr[4][4] = 1;
#endif
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			go(i, j, 0, 0);
	/*
	ㅁㅁㅁ
	  ㅁ
	*/
	if(j + 2 < M && i + 1 < N){
		int tmp = arr[i][j];
		tmp += arr[i][j+1];
		tmp += arr[i][j+2];
		tmp += arr[i+1][j+1];
		if(tmp > maximum) maximum = tmp;
	}
	/*
	  ㅁ
	ㅁㅁㅁ
	*/
	if(j + 2 < M && i + 1 < N){
		int tmp = arr[i+1][j];
		tmp += arr[i+1][j+1];
		tmp += arr[i+1][j+2];
		tmp += arr[i][j+1];
		if(tmp > maximum) maximum = tmp;
	}
	/*
	ㅁ
	ㅁㅁ
	ㅁ
	*/
	if(j + 2 < M && i + 1 < N){
		int tmp = arr[i][j];
		tmp += arr[i+1][j];
		tmp += arr[i+2][j];
		tmp += arr[i+1][j+1];
		if(tmp > maximum) maximum = tmp;
	}
	/*
	  ㅁ
	ㅁㅁ
	  ㅁ
	*/
	if(j + 2 < M && i + 1 < N){
		int tmp = arr[i][j+1];
		tmp += arr[i+1][j+1];
		tmp += arr[i+2][j+1];
		tmp += arr[i+1][j];
		if(tmp > maximum) maximum = tmp;
	}
		}
	cout << maximum << endl;
	return 0;
}

