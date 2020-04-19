#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void go(vector<vector<int>> board, int idx)
{
	if(idx == 9*9){
		bool findZero = false;
		for(auto &i : board){
			if(find(i.begin(), i.end(), 0) != i.end()){
				findZero = true;
				break;
			}
		}
		if(!findZero){
			for(int i = 0; i < 9; i++){
				for(int j = 0; j < 9; j++)
					cout << board[i][j] << ' ';
				cout << endl;
			}
		}
		return;
	}
	int x = idx % 9, y = idx / 9;
	if(board[y][x] != 0)
		go(board, idx + 1);
	else {
		vector<int>list;
		for(int i = 0; i < 9; i++){
			list.push_back(board[y][i]);
			list.push_back(board[i][x]);
			int newX = x / 3;
			int newY = y / 3;
			for(int i = 0; i < 3; i++)
				for(int j = 0; j < 3; j++)
					list.push_back(board[newY*3+i][newX*3+j]);
		}
		sort(list.begin(), list.end());
		list.erase(unique(list.begin(), list.end()), list.end());
		vector<int>cand;
		for(int i = 1; i <= 9; i++){
			if(find(list.begin(), list.end(), i) == list.end())
				cand.push_back(i);
		}
		for(auto &i : cand){
			board[y][x] = i;
			go(board, idx + 1);
		}
	}
	return;
}

int main(void)
{
	vector<vector<int>>board(9, vector<int>(9, 0));
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			cin >> board[i][j];
	go(board, 0);
	return 0;
}
