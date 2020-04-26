#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
int p[1000];

int main(void)
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> p[i];
	sort(p, &p[N]);
	int sum = 0;
	int ans = 0;
	for(int i = 0; i < N; i++){
		sum += p[i];
		ans += sum;
	}
	cout << ans << endl;
	return 0;
}
