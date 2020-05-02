#include <iostream>
#include <cmath>

using namespace std;

char map[10000][10000];

int x, y, cnt;

int x_list[10];
int y_list[10];
int a = 0;

void make_map(int d, int r, int c)
{
	if(d == 0){
		for(int i = 0; i < 5; i++)
			map[r][c+i] = '*';
		map[r-1][c+1] = '*';
		map[r-1][c+3] = '*';
		map[r-2][c+2] = '*';
		for(int i = 2; i >= 0; i--){
			for(int j = 0; j < 5; j++){
				if(map[r-i][j] != '*')
					putchar(' ');
				else printf("%c", map[r-i][j]);
			}
			putchar('\n');
		}
		return;
	}
	int x_len = x_list[d-1];
	int y_len = y_list[d-1];
	make_map(d-1, r, c);
	make_map(d-1, r, c + y_len + 1);
	make_map(d-1, r - x_len, c + y_len/2 + 1);
	return;
}

int main(void)
{
	cin >> x;

	int tmpX = 3, tmpY = 5;

	for(int i = 0; i < 10; i++){
		x_list[i] = tmpX;
		y_list[i] = tmpY;
		tmpX *= 2;
		tmpY = tmpY * 2 + 1;
	}

	for(int i = 0; i < 10; i++)
		if(x_list[i] == x){
			cnt = i;
			y = y_list[i];
			break;
		}
	
	make_map(cnt, x - 1, 0);

	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(map[x][y] != '*')
				putchar(' ');
			else putchar(map[x][y]);
		}
		putchar('\n');
	}

	return 0;
}
