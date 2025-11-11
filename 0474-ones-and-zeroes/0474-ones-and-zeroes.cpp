class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j] = max number of strings that can be formed with i zeros and j ones
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string &str : strs) {
            int zeros = 0, ones = 0;
            for (char c : str) {
                if (c == '0') zeros++;
                else ones++;
            }

            // traverse backwards to avoid recomputing in the same iteration
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }

        return dp[m][n];
    }
};
