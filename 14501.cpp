#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<pair<int, int>>val, vector<bool>day, int pos, int cur, int N)
{
    if(pos < N){
        if(!day[pos]){
            if(pos + val[pos].first - 1 < N){
                for(int i = 0; i < val[pos].first; i++){
                    day[pos + i] = true;
                }
                int tmp1 = check(val, day, pos + 1, cur + val[pos].second, N);                
                for(int i = 0; i < val[pos].first; i++){
                    day[pos + i] = false;
                }
                int tmp2 = check(val, day, pos + 1, cur, N);
                int max = tmp1;
                if(max < tmp2)
                    max = tmp2;
                cur = max;
            }
        }
    }
    return cur;
}

int main(void)
{
    int N;
    cin >> N;
    vector<pair<int, int>>val(N);
    vector<bool>day(N, false);
    for(int i = 0; i < N; i++)
        cin >> val[i].first >> val[i].second;
    cout << check(val, day, 0, 0, N) <<endl;
    return 0;
}
