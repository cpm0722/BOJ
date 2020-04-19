#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;

char board[20][20];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int answer = 0;

bool history[26];

bool isIn(int x, int y) { return x >= 0 && x < C && y >= 0 && y < R; }

void go(int x, int y, int cnt)
{
	if(cnt > answer) answer = cnt;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(isIn(nx, ny)){
			if(!history[board[ny][nx] - 'A']){
				history[board[ny][nx]-'A'] = true;
				go(nx, ny, cnt + 1);
				history[board[ny][nx]-'A'] = false;
			}
		}
	}
	return;
}

int main(void)
{
	cin >> R >> C;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			cin >> board[i][j];
	history[board[0][0]-'A'] = true;
	go(0, 0, 1);
	cout << answer << endl;
	return 0;
}
