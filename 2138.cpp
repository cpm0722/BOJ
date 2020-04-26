#include <iostream>
#include <algorithm>

using namespace std;

int N;
int src[100001];
int cpy[100001];
int dst[100001];

void change(int i){
	if(i <= 1)
		return;
	if(i > N)
		return;
	if(i == N){
		cpy[i] = 1-cpy[i];
		cpy[i-1] = 1-cpy[i-1];
	}
	else{
		cpy[i+1] = 1-cpy[i+1];
		cpy[i] = 1-cpy[i];
		cpy[i-1] = 1-cpy[i-1];
	}
}

int main(void)
{
	cin >> N;
	for(int i = 1; i <= N; i++){
		scanf("%1d", &src[i]);
		cpy[i] = src[i];
	}
	for(int i = 1; i <= N; i++)
		scanf("%1d", &dst[i]);

	int cnt1 = 0;
	for(int i = 2; i <= N; i++){
		if(cpy[i-1] != dst[i-1]){
			change(i);
			cnt1++;
		}
	}
	if(cpy[N] != dst[N])
		cnt1 = -1;

	
	for(int i = 1; i <= N; i++)
		cpy[i] = src[i];

	int cnt2 = 1;
	cpy[1] = 1-cpy[1];
	cpy[2] = 1-cpy[2];
	for(int i = 2; i <= N; i++){
		if(cpy[i-1] != dst[i-1]){
			change(i);
			cnt2++;
		}
	}
	if(cpy[N] != dst[N])
		cnt2 = -1;
	
	if(cnt1 == -1 && cnt2 == -1)
		cout << "-1" << endl;
	else if(cnt1 == -1)
		cout << cnt2 << endl;
	else if(cnt2 == -1)
		cout << cnt1 << endl;
	else
		cout << min(cnt1,cnt2) << endl;

	return 0;
}
