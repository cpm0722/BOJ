#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool make[1501][1501];

int sum;

void go(int x, int y)
{
	int a = x, b = y, c = sum - x - y;
	if(make[a][b]) return;
	make[a][b] = true;
	if(a == b && a == c && b == c)
		return;
	if(a < b)
		go(a + a, b - a);
	else
		go(a - b, b + b);
	if(a < c)
		go(a + a, c - a);
	else
		go(a - c, c + c);
	if(b < c)
		go(b + b, c - b);
	else
		go(b - c, c + c);
	return;
}

int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;
	sum = A + B + C;
	if(sum % 3){
		cout << 0 << endl;
		return 0;
	}
	int x = A, y = B;
	go(x, y);
	if(make[sum/3][sum/3])
		cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}
