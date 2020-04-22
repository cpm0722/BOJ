#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;

long long S, T;

string go(long long src, long long dst)
{
	if(src == dst){
		string ans = "0";
		return ans;
	}
	set<long>numSet;
	string str = "";
	long now = src;
	numSet.insert(src);
	queue<pair<string,long>> q;
	q.push(make_pair(str, src));
	while(!q.empty()){
		tie(str,now) = q.front(); q.pop();
		if(now == dst)
			break;
		long next[4];
		next[0] = now * now;
		next[1] = now + now;
		next[2] = now - now;
		if(now != 0)
			next[3] = now / now;
		for(int i = 0; i < 4; i++){
			if(now == 0 && i == 3) continue;
			if(numSet.count(next[i]) == 0){
				string op;
				switch(i){
					case 0:
						op = "*";
						break;
					case 1:
						op = "+";
						break;
					case 2:
						op = "-";
						break;
					case 3:
						op = "/";
						break;
				}
				numSet.insert(next[i]);
				q.push(make_pair(str + op, next[i]));
			}
		}
	}
	if(now != dst)
		str = "-1";
	return str;
}

int main(void)
{
	cin >> S >> T;
	cout << go(S, T) << endl;
	return 0;
}
