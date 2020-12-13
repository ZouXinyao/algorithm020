class Solution {
public:
    int jump(vector<int>& nums) {
        int maxLen = 0, thisEnd = 0, res = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            maxLen = max(maxLen, i + nums[i]);
            if(i == thisEnd) {
                res++;
                thisEnd = maxLen;
            }
        }
        return res;
    }
};