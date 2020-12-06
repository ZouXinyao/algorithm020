class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        //因为后面判断重复是比较前后元素是否相同，所以需要排序
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtrack(res, path, used, nums);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int> path, vector<bool>& used, vector<int>& nums){
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            /*
            * 与46的区别就在状态列表used里: 
            * 如果这个值是重复的(nums[i] == nums[i - 1]);
            * 并且前一个值存下来了(used[i - 1] == false)。
            * 所以当前这个分支就不需要了，因为上一个分支已经处理了。
            */
            if(used[i] || (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(res, path, used, nums);
            used[i] = false;
            path.pop_back();
        }
    }
};