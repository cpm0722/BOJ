#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string src;
string dst;

int main(void)
{
	cin >> src;
	cin >> dst;
	while(dst.length() > src.length()){
		if(dst[dst.length()-1] == 'A'){
			dst.pop_back();
		}
		else{
			dst.pop_back();
			reverse(dst.begin(), dst.end());
		}
	}
	if(dst == src)
		cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}
