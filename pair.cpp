#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main(void)
{
	pair<string,int> p1;
	p1 = make_pair("pair1", 1);
	pair<string, int> p2 = {"pair2", 2};
	cout << p1.first << ' ' << p1.second << endl;
	cout << p2.first << ' ' << p2.second << endl;
	return 0;
}
