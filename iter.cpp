#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> vect;
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	//vector<int>를 가리키는 iterator 변수 생성
	vector<int>::iterator iter;
	//iterator가 end와 같을 때까지 반복 (부등호 사용 X)
	for(iter = vect.begin(); iter != vect.end(); iter++)
		cout << *iter << endl;
	for(auto &i : vect)
		cout << i << endl;
	return 0;
}
