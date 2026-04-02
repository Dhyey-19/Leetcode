class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& coins, int i, int j, int skips) {
        if(i >= m || j >= n) return INT_MIN;

        if(dp[i][j][skips] != INT_MIN) return dp[i][j][skips];

        if(i == m - 1 && j == n - 1) {
            if(coins[i][j] < 0 && skips > 0) {
                return dp[i][j][skips] = 0;
            }
            return dp[i][j][skips] = coins[i][j];
        }

        // Take
        int take = coins[i][j] + max(
            solve(coins, i+1, j, skips),
            solve(coins, i, j+1, skips)
        );

        // Skip
        int skip = INT_MIN;
        if(coins[i][j] < 0 && skips > 0) {
            skip = max(
                solve(coins, i+1, j, skips-1),
                solve(coins, i, j+1, skips-1)
            );
        }

        return dp[i][j][skips] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        return solve(coins, 0, 0, 2);
    }
};