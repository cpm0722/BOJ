#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int main(void)
{
	int i;
	vector<int> vi;
	vi.push_back(1);vi.push_back(2);vi.push_back(3);
	for(int i = 0; i < 3; i++)
		printf("%d ", vi[i]);
	putchar('\n');
	for (i=0;i<6;i++) {
		next_permutation(vi.begin(),vi.end());
		for(int i = 0; i < 3; i++)
			printf("%d ", vi[i]);
		putchar('\n');
	}
	return 0;
}
