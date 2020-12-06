class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        /*
        * 这里如果不记录数组元素状态，会输出有重复元素的数组。
        * 例：nums={1,2,3} 会输出{1,1,1}这样的值。
        * 为了去掉重复元素的数组，需要有一个vector记录当前元素是否已经保存下来。
        */
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
            //保存下来了，就直接存下一个值。
            if(used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(res, path, used, nums);
            used[i] = false;
            path.pop_back();
        }
    }
};