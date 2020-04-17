#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vector1(0);
	vector1.push_back(5);
	vector1.push_back(4);
	vector1.push_back(3);
	vector1.resize(5);
	for(vector<int>::iterator iter = vector1.begin(); iter != vector1.end(); iter++)
		printf("%d", *iter);
	putchar('\n');
	vector1.resize(3);
	for(vector<int>::iterator iter = vector1.begin(); iter != vector1.end(); iter++)
		printf("%d", *iter);
	putchar('\n');
	vector<int> vector2 = vector<int>(vector1.begin(), vector1.end());
	vector1[0] = 0;
	for(vector<int>::iterator iter = vector1.begin(); iter != vector1.end(); iter++)
		printf("%d", *iter);
	putchar('\n');
	for(vector<int>::iterator iter = vector2.begin(); iter != vector2.end(); iter++)
		printf("%d", *iter);
	putchar('\n');
	return 0;
}
