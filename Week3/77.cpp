class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(k > n || k <= 0) return {};
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, 1, k, n);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int> path, int level, int k, int n) {
        if(path.size() == k) {
            res.push_back(path);
            return;
        }

        for(int i = level; i <= n; i++) {
            path.push_back(i);
            dfs(res, path, ++level, k, n);
            path.pop_back();                //回溯到上一层，应该是这样。
        }
    }
};