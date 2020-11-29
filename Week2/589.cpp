class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        orderMain(res, root);
        return res;
    }

    void orderMain(vector<int>& res, Node* node) {
        if(node == nullptr) return;
        res.push_back(node->val);
        for(int i = 0; i < node->children.size(); i++) {
            orderMain(res, node->children[i]);
        }
    }
};