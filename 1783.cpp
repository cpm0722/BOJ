#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int main(void)
{
	cin >> N >> M;

	int cnt = 1;

	if(N < 3 && M < 3)
		cnt = 1;
	else if(N == 1)
		cnt = 1;
	else if(N == 2){
		if(M < 9)
			cnt += (M-1) / 2;
		else cnt += 3;
	}
	else{
		if(M == 1)
			cnt = 1;
		else if(M == 2)
			cnt += 1;
		else if(M >= 3 && M <= 4)
			cnt += (M - 1) / 1;
		else if(M == 5 || M == 6)
			cnt += 3;
		else {
			cnt += 4;
			cnt += (M - 7) / 1;
		}
	}

	cout << cnt << endl;

	return 0;
}
