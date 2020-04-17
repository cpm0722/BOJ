#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool check(vector<char> op, vector<int>num){
    int len = op.size();
    for (int i = 0; i < len; i++){
        if(op[i] == '<'){
            if(num[i] > num[i + 1])
                return false;
        }
        else if(op[i] == '>'){
            if(num[i] < num[i + 1])
                return false;
        }
    }
    return true;
}

int main(void)
{
    int k;
    cin >> k;
    vector<char> op(k);
    for(int i = 0; i < k; i++)
        cin >> op[i];
    vector<int> max;
    vector<int> min;
    for(int i = 0; i < k + 1; i++){
        min.push_back(i);
        max.push_back(9 - i);
    }
    do{
        if(check(op, max))
            break;
    }while(prev_permutation(max.begin(), max.end()));
    do{
        if(check(op, min))
            break;
    }while(next_permutation(min.begin(), min.end()));
    vector<string>result(2);
    for(int i = 0; i < k + 1; i++){
        char tmp[2];
        tmp[1] = '\0';
        tmp[0] = max[i] + '0';
        result[0] += tmp;
        tmp[0] = min[i] + '0';
        result[1] += tmp;
    }
    cout << result[0] << endl << result[1];
    return 0;
}
