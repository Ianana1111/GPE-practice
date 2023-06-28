#include <bits/stdc++.h>

using namespace std;

// reference: https://ppt.cc/f8d2Lx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int Cas;
int L, S;
int dp[27][27][352]; // dp[i][j][k] 表只使用前 i 個字母，組成長度為 j，總和為 k 的字串的所有情況數

void compute()
{
    for (int i = 1; i <= 26; ++i) dp[i][1][i] = 1;
    for (int i = 1; i <= 26; ++i) for (int j = 1; j <= i; ++j)
    {
        for (int k = 1; k <= 351; ++k)
        {
            dp[i][j][k] += dp[i - 1][j][k];
            // 判斷是否能將 i 接上
            if (k >= i) dp[i][j][k] += dp[i - 1][j - 1][k - i];
        }
    }
}

int main()
{
    compute();
    while (cin >> L >> S && L && S)
    {
        cout << "Case " << ++Cas << ": ";
        // 由於嚴格遞增，因此最多 26 個字母，S 最大為 351
        if (L > 26 || S > 351) cout << "0\n";
        else cout << dp[26][L][S] << '\n';
    }
}