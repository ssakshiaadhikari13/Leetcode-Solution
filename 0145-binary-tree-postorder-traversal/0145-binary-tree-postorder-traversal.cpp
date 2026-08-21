/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void postod(TreeNode* root ,vector<int>&data){
    if(root==NULL)
    return ;

    postod(root->left,data);
    postod(root->right,data);
    data.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>data;
        postod(root,data);
        return data ;
        
    }
};