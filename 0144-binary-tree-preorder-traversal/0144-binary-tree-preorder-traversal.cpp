class Solution {
public:

    void preorder(TreeNode* root, vector<int>& data) {
        if(root == NULL)
            return;

        data.push_back(root->val);  // Root
        preorder(root->left, data); // Left
        preorder(root->right, data); // Right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> data;

        preorder(root, data);

        return data;
    }
};