class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp = grid;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else if(i == 0) dp[i][j] = grid[i][j] + dp[i][j - 1];
                else if(j == 0) dp[i][j] = grid[i][j] + dp[i - 1][j];
                // DP方程：左、上最小值 + 当前值；
                else dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};