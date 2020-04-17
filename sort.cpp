#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int a[10] = {5, 10, 4, 3, 1, 8, 6, 9, 7, 2};
	for(int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	putchar('\n');
	printf("%d\n", *upper_bound(a, a + 10, 5));
	printf("%d\n", *lower_bound(a, a + 10, 5));
	return 0;
}
