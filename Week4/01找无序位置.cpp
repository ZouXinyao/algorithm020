#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int findUnsortIdx(vector<int>& nums);

int main() {
    vector<int> testAry({5, 6, 7, 1, 1, 1, 2, 3, 4});
    cout << findUnsortIdx(testAry) << endl;
}

/* 这个是没有重复元素的情况，与求最大或最小元素一样；
 * 如果有重复元素，就不一样了，边界位置、最小位置重复都是问题。
 * 暂时没有思路。
*/
int findUnsortIdx(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    int min = INT_MAX;
    int idx = -1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(min > nums[m]) {
            idx = m;
            min = nums[m];
        }
        if(nums[m] < nums[r]) r = m - 1;
        else l = m + 1;
    }
    return l;
}