#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	for(queue<int>::iterator iter = q.begin(); iter != q.end(); iter++)
		printf("%d ", *iter);
	putchar('\n');
	return 0;
}
