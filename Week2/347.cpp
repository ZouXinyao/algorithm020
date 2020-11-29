class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto& num : nums) {
            m[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto& i : m) {
            pq.push({i.second, i.first});
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            pair<int, int> tmp = pq.top();
            pq.pop();
            res.push_back(tmp.second);
        }
        return res;
    }
};