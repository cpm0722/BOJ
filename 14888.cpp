#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> num(N);
    for(int i = 0; i < N; i++)
        cin >> num[i];
    vector<int> op(4);
    for(int i = 0; i < 4; i++)
        cin >> op[i];
    vector<char>c;
    while(op[0] > 0){
        c.push_back('+');
        op[0]--;
    }
    while(op[1] > 0){
        c.push_back('-');
        op[1]--;
    }
    while(op[2] > 0){
        c.push_back('*');
        op[2]--;
    }
    while(op[3] > 0){
        c.push_back('/');
        op[3]--;
    }
	cout << "operator: ";
	for(auto&i : c)
		cout << i;
	cout << endl;;
	cout << c.size() << endl;
	sort(c.begin(), c.end());
    int max = INT32_MIN, min = INT32_MAX;
   	while(1){ 
        int tmp = num[0];
        for(int i = 0; i < N - 1; i++){
            switch(c[i]){
                case '+':
                    tmp += num[i + 1];
                    break;
                case '-':
                    tmp -= num[i + 1];
                    break;
                case '*':
                    tmp *= num[i + 1];
                    break;
                case '/':
                    tmp /= num[i + 1];
                    break;
            }
        }
        if(max < tmp)
            max = tmp;
        if(min > tmp)
            min = tmp;
		if(!next_permutation(c.begin(), c.end())){
			printf("끝!!\n");
			break;
		}
		else {
			for(auto&i : c)
				cout << i;
			cout << endl;;
		}
    }
    cout << max << endl << min << endl;
    return 0;
}

