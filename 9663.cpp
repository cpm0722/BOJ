#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
int board[15][15];
vector<bool>col(15, false);
vector<bool>right_bottom(30, false);
vector<bool>left_bottom(30, false);

int go(int row, int cnt)
{
	int sum = 0;
	if(cnt == N)
		return 1;
	if(row == N)
		return 0;
	for(int i = 0; i < N; i++){
		if(!col[i] && !right_bottom[row-i+N] && !left_bottom[row+i]){
			col[i] = true;
			right_bottom[row-i+N] = true;
			left_bottom[row+i] = true;
			sum += go(row+1, cnt+1);
			col[i] = false;
			right_bottom[row-i+N] = false;
			left_bottom[row+i] = false;
		}
	}
	return sum;
}

int main(void)
{
	cin >> N;
	cout << go(0, 0) << endl;
	return 0;
}
