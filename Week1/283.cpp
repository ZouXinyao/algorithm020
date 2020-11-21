//双指针，快指针一直走，慢指针只有元素不为0时才走，当慢指针为0、快指针不为0时交换。
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() < 2) return;
        int slow = 0;
        for(int fast = 1; fast < nums.size(); fast++) {
            if(nums[fast] != 0 && nums[slow] == 0) swap(nums, fast, slow);
            if(nums[slow] != 0) slow++;
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};