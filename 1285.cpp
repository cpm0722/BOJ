#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char coin[20][20];

char flip(char c){
	if(c == 'H')
		return 'T';
	else if(c == 'T')
		return 'H';
}

int go(void)
{
	int ans = INT32_MAX;
	for(int b = 0; b < (1 << N); b++){	//b는 열에 대해 flip이 되었는지에 대한 값(2^N)
		int sum = 0;	//전체 T 개수
		for(int i = 0; i < N; i++){	//행,열 순으로 탐색
			int cnt = 0;	//현재 행에서 T의 개수
			for(int j = 0; j < N; j++){
				char c = coin[i][j];
				if(b & (1 << j)) c = flip(c);	//현재 열이 flip된 상태일 경우
				if(c == 'T') cnt++;
			}
			cnt = min(cnt, N - cnt);	//T가 더 많을 경우 flip, H가 더 많을 경우 flip하지 않는다고 가정한 후 둘 중 더 작은 값 취함
			sum += cnt;
		}
		if(sum < ans)
			ans = sum;
	}
	return ans;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++){
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
			coin[i][j] = str[j];
	}
	cout << go() << endl;
	return 0;
}
