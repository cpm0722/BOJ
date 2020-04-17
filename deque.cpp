#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
	deque<int> dq;
	dq.push_front(3);
	dq.push_front(4);
	dq.push_back(2);
	dq.push_front(5);
	dq.push_back(1);
	printf("%d %d\n", dq.front(), dq.back());
	for(deque<int>::iterator iter = dq.begin(); iter != dq.end(); iter++)
		printf("%d ", *iter);
	putchar('\n');
	return 0;
}
