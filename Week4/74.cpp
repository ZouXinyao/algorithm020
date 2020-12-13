class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;
        if(r == 0) return search(matrix[0], target);
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(target >= matrix[m][0] && (m == matrix.size() - 1 || target < matrix[m + 1][0])) return search(matrix[m], target);
            else if(target < matrix[m][0]) r = m - 1;
            else l = m + 1;
        }
        return false;
    }

    bool search(vector<int>& ary, int target) {
        int l = 0;
        int r = ary.size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(target == ary[m]) return true;
            else if(target < ary[m]) r = m - 1;
            else l = m + 1;
        }
        return false;
    }
};