#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	multiset<int> s;
	s.insert(5);
	s.insert(6);
	s.insert(7);
	printf("size: %lu\n", s.size());
	if(s.find(6) != s.end())
		printf("6 있음\n");
	else printf("6 없음\n");
	s.erase(s.begin());
	printf("size: %lu\n", s.size());
	s.erase(s.find(7));
	printf("size: %lu\n", s.size());
	s.erase(s.begin(), s.end());
	printf("size: %lu\n", s.size());
	return 0;
}
