class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                    if(matrix[i][j] == '1') res = max(1, res);
                }
                
                else if(matrix[i][j] == '1') {
                    // DP方程：如果是'1'，当前边长为：左、左上、上，最小值+1
                    int tmp = myMin(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                    res = max(tmp, res);
                    dp[i][j] = tmp;
                }
            }
        }
        return res * res;
    }

    int myMin(int a, int b, int c) {
        return min(min(a, b), c);
    }
};