#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<vector<int>>val(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> val[i][j];
    vector<int>team(N, 0);
    for(int i = 0; i < N / 2; i++)
        team[i] = 1;
    sort(team.begin(), team.end());
    int diff = INT32_MAX;
    do{
        int s0 = 0, s1 = 0;
        for(int i = 0; i < N; i++){
            if(team[i] == 0){
                for(int j = 0; j < N; j++){
                    if(team[j] == 0)
                        s0 += val[i][j];
                }
            }
            else{
                for(int j = 0; j < N; j++){
                    if(team[j] == 1)
                        s1 += val[i][j];
                }
            }
        }
        int now = s0 - s1;
        if(now < 0)
            now *= -1;
        if(diff > now)
            diff = now;
    }while(next_permutation(team.begin(), team.end()));
    cout << diff << endl;
    return 0;
}
