#include <iostream>
#include <memory.h>

using namespace std;

int dp[27][27][352];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int L, S, cases = 0;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;

	for (int i = 1; i <= 26; ++i) 
        for (int j = 0; j <= i; ++j) 
            for (int k = 0; k <= 351; ++k){
                dp[i][j][k] = dp[i - 1][j][k];
                if (j && k >= i) dp[i][j][k] += dp[i - 1][j - 1][k - i];
            }

	while (cin >> L >> S, L && S) cout << "Case " << ++cases << ": " << ((L <= 26 && S <= 351) ? dp[26][L][S] : 0) << "\n";

	return 0;
}