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
    vector<int> inorderTraversal(TreeNode* root) {
        // left - root - right
        vector<int> res;
        recursive_inorderTraversal(root, res);
        return res;
    }

    void recursive_inorderTraversal(TreeNode* root, vector<int> & res){
        if(root){
            recursive_inorderTraversal(root->left, res);
            res.push_back(root->val);
            recursive_inorderTraversal(root->right, res);
        }
    }
};