#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int list[10];

int go(int dst)
{
	int cnt = 0;
	int i;
	for(i = N; i >= 0; i--){
		if(dst > list[i])
			break;
	}
	for(; i >= 0; i--){
		if(list[i] != 0){
			cnt += dst / list[i];
			dst -= (dst / list[i]) * list[i];
		}
		if(dst == 0)
			break;
	}
	return cnt;
}

int main(void)
{
	cin >> N >> K;
	for(int i = 0; i < N; i++)
		cin >> list[i];
	cout << go(K) << endl;
	return 0;
}
