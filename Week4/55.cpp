class Solution {
public:
    bool canJump(vector<int>& nums) {
        int flag = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(flag < i) return false;
            flag = max(flag, i + nums[i]);
        }
        
        return true;
    }
};