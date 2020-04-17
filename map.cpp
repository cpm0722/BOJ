#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	map<string, int>m;
	m.insert(make_pair("str1", 1));
	m.insert(make_pair("str2", 2));
	m.insert({"str3", 3});
	m.insert(pair<string, int>("str3", 4));
	printf("%lu\n", m.count("str3"));
	printf("%lu\n", m.size());
	printf("%d\n", m["str3"]);
	printf("%d\n", m.find("str3")->second);
	return 0;
}
