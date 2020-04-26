#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K;

int main(void)
{
	cin >> N >> K;
	int len = K;	//B를 미리 배치
	for(int a = 0; a <= N; a++){
		int b = N - a;
		if(a * b < K) continue;
		vector<int>cnt(b+1);	//B 사이에 A를 얼마나 넣을지 저장
		for(int i = 0; i < a; i++){
			int x = min(b,K);
			cnt[x]++;
			K -= x;
		}
		int i;
		for(i = b; i >= 0; i--){
			while(cnt[i] > 0){
				cout << 'A';
				cnt[i]--;
			}
			if(i > 0)
				cout << 'B';
		}
		cout << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}
