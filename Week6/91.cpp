class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        /* 
         * DP方程的边界有点细节
         * 当前位置为0：前一个位置是1或2，i结果 = i - 2结果，因为要和上一个看成一体。
         * 当前位置不为0：与前一个合一起<26且>0：i结果 = i - 1结果+ i - 2结果
         *               否则：i结果 = i - 1结果
        */
        for(int i = 2; i < s.size() + 1; i++) {
            if(s[i - 1] == '0') {
                if(s[i - 2] > '2' || s[i - 2] == '0') return 0;
                else dp[i] = dp[i - 2];
                continue;
            }
            if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else dp[i] = dp[i - 1];
        }
        return dp[s.size()];
    }
};