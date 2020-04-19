#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string b[20];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;

int answer = INT32_MAX;

bool isIn(int x, int y) { return (x>=0 && x<M) && (y>=0 && y<N); }

void go(int pos[4], int cnt)
{
	if(cnt == 11) return;
	int t = 0;
	if(isIn(pos[0], pos[1])) t++;
	if(isIn(pos[2], pos[3])) t++;
	if(t == 0)
		return;
	if(t == 1){
		if(answer > cnt)
			answer = cnt;
		return;
	}
	int answer = -1;
	for(int i = 0; i < 4; i++){
		int tmp[4];
		for(int j = 0; j < 4; j++) tmp[j] = pos[j];
		pos[0] += dx[i];
		pos[1] += dy[i];
		pos[2] += dx[i];
		pos[3] += dy[i];
		if((isIn(pos[0], pos[1])) && (b[pos[1]][pos[0]] == '#')){
			pos[0] = tmp[0];
			pos[1] = tmp[1];
		}
		if((isIn(pos[2], pos[3])) && (b[pos[3]][pos[2]] == '#')){
			pos[2] = tmp[2];
			pos[3] = tmp[3];
			}
		go(pos, cnt + 1);
		for(int j = 0; j < 4; j++) pos[j] = tmp[j];
	}
	return;
}

int main(void)
{
	cin >> N >> M;
	int pos[4];
	for(int i = 0; i < N; i++)
		cin >> b[i];
	int cnt = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < b[i].size(); j++){
			if(b[i][j] == 'o'){
				pos[cnt++] = j;
				pos[cnt++] = i;
			}
		}
	go(pos, 0);
	cout << (answer==INT32_MAX ? -1 : answer) << endl;
	return 0;
}
