class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res;
        for(int i = 1; i < prices.size(); i++) {
            int tmp = prices[i] - prices[i - 1];
            if(tmp > 0) res += tmp;
        }
        return res;
    }
};