#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	vector<int>list(2);
	list[0] = 1;
	list[1] = 2;
	sort(list.begin(), list.end(), greater<int>());
	do{
	for(auto &i : list)
		cout << i << ' ';
	cout << endl;
	}while(next_permutation(list.begin(), list.end()));
	return 0;
}
