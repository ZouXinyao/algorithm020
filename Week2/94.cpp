class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        orderMain(res, root);
        return res;

    }
    void orderMain(vector<int>& res, TreeNode* node) {
        if(node == nullptr) return;
        orderMain(res, node->left);
        res.push_back(node->val);
        orderMain(res, node->right);
    }
};