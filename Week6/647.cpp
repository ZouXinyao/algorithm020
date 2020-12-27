class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                /* 
                 * 子问题：s[j - i : j]是不是回文串
                 * 状态暂存数组：长宽都为s.size()的二维数组
                 * DP方程：子串的两头相等 && j - i + 1与j - 1位置(s[j - i : j]左右都缩一格)是不是回文串。
                 */
                if((i < 2 && s[j - i] == s[j]) || (s[j - i] == s[j] && dp[j - i + 1][j - 1] == 1)) {
                    dp[j - i][j] = 1;
                    res++;
                }
            }
        }
        return res;
    }
};