class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        swap(nums, 0, nums.size());
        swap(nums, 0, k % nums.size());
        swap(nums, k % nums.size(), nums.size());
    }
    void swap(vector<int>& nums, int left, int right) {
        for(int i = left; i < left + (right - left) / 2; i++) {
            int tmp = nums[i];
            nums[i] = nums[right - i + left - 1];
            nums[right - i + left - 1] = tmp;
        }
    }
};