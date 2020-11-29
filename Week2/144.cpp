class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        orderMain(res, root);
        return res;

    }
    void orderMain(vector<int>& res, TreeNode* node) {
        if(node == nullptr) return;
        res.push_back(node->val);
        orderMain(res, node->left);
        orderMain(res, node->right);
    }
};
