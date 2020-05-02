#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1000];
int d[1000];	//d[i]: i칸까지 왔을 때의 최소 점프 횟수

void go()
{
	for(int i = 0; i < N; i++){
		if(d[i] == -1) continue;
		for(int j = 0; j <= A[i]; j++){
			if(i+j < N){
				if(d[i+j] == -1)
					d[i+j] = d[i]+1;
				else 
					d[i+j] = min(d[i+j], d[i]+1);
			}
			else
				break;
		}
	}
	return;
}

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++){
		scanf("%d", &A[i]);
		d[i] = -1;
	}

	d[0] = 0;
	go();

	cout << d[N-1] << endl;
	return 0;
}
