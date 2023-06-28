#include <iostream>
#include <cstring>
using namespace std;
int dp[55][55]; //最多50個切割的地方
int a[55]; //第1～N個切割的地方，由小到大排列好。
 
int solve(int x, int y){
    if (~dp[x][y]) return dp[x][y]; //記憶化
    if (x+1 == y) return dp[x][y] = 0;
    int cost = 0x3F3F3F3F;
    for (int i = x+1; i < y; i++){
        //枚舉中間的切割點
        cost = min(cost, solve(x, i) + solve(i, y));
    }
    return dp[x][y] = cost + a[y] - a[x];
}
 
int main() {
    int L, N;
    while (cin >> L){
        if (L == 0) break;
        memset(a, 0, sizeof(a));
        memset(dp, -1, sizeof(dp));
        cin >> N;
        for (int i = 1; i <= N; i++){
            cin >> a[i];
        }
        a[N+1] = L;
        cout << "The minimum cutting is " << solve(0, N+1) << ".\n";
    }
    return 0;
}// 0 3 7 10   0 3
//           0 1  1 3             0 2  2 3
//           0     cost = 7       7