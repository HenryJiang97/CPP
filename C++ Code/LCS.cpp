// LCS
vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MIN / 2));

for (int i = 0; i <= n1; i++)    dp[i][0] = 0;
for (int j = 0; j <= n2; j++)    dp[0][j] = 0;

for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
        if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = max(dp[i - 1][j - 1] + (int)s1[i - 1] + (int)s2[j - 1],
                            max(dp[i - 1][j], dp[i][j - 1]));
        } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}