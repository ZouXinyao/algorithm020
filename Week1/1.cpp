//暴力法，返回值处理有问题。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

//哈希
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        for(int i = 0; i < nums.size(); i++) {
            if(hashTable.find(target - nums[i]) != hashTable.end()) {
                return {hashTable[target - nums[i]], i};
            }
            hashTable[nums[i]] = i;
        }
        return {};
    }
};
