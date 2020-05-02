#include <iostream>
#include <algorithm>

using namespace std;

int N;
int T[1500001];
int P[1500001];
int d[1500001];	//d[i]: i일까지 벌 수 있는 최대 금액

void go()
{
	for(int i = 0; i < N; i++){
		if(i+T[i] <= N)
			d[i+T[i]] = max(d[i+T[i]], d[i] + P[i]);
		d[i+1] = max(d[i+1], d[i]);
	}
	return;
}

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++)
		scanf("%d%d", &T[i], &P[i]);

	d[0] = 0;

	go();

	cout << d[N] << endl;

	return 0;
}
