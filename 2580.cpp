#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[9][9];
bool col[10][10];
bool row[10][10];
bool square[10][10];

bool go(int idx)
{
	if(idx == 9*9){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++)
				cout << board[i][j] << ' ';
			cout << endl;
		}
		return true;
	}
	int x = idx / 9, y = idx % 9;
	if(board[x][y] != 0)
		return go(idx + 1);
	else {
		for(int i = 1; i <= 9; i++){
			if(!row[x][i] && !col[y][i] && !square[(x/3)*3+(y/3)+1][i]){
				board[x][y] = i;
				row[x][i] = col[y][i] = square[(x/3)*3+(y/3)+1][i] = true;
				if(go(idx + 1))
					return true;
				board[x][y] = 0;
				row[x][i] = col[y][i] = square[(x/3)*3+(y/3)+1][i] = false;
			}
		}
	}
	return false;
}

int main(void)
{
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++){
			cin >> board[i][j];
			row[i][board[i][j]] = true;
			col[j][board[i][j]] = true;
			square[(i/3) * 3 + (j/3) +1][board[i][j]] = true;
		}
	go(0);
	return 0;
}
