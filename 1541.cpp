#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;

int num[50];
char op[50];
int numPos = 0;
int opPos = 0;

void tokenize(void)
{
	int len = str.size();
	for(int i = 0; i < len; i++){
		if(str[i] >= '0' && str[i] <= '9'){
			int tmp = 0;
			while(str[i] >= '0' && str[i] <= '9'){
				tmp = tmp * 10 + (str[i] - '0');
				i++;
			}
			i--;
			num[numPos++] = tmp;
		}
		else{
			op[opPos++] = str[i];
		}
	}
	return;
}

int main(void)
{
	cin >> str;

	tokenize();

	long long ans = num[0];
	int i = 0;
	for(int i = 0; i < opPos; i++){
		if(op[i] == '-'){
			ans -= num[i+1];
			i++;
			while(i < opPos && op[i] == '+'){
				ans -= num[i+1];
				i++;
			}
			i--;
		}
		else
			ans += num[i+1];
	}

	cout << ans << endl;

	return 0;
}
