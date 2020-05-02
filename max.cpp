#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int main(void)
{
	tuple<int,int,int>list = make_tuple(5, 120000, 52);
	printf("%d\n", max(list));
	return 0;
}
