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
    void preorder(TreeNode* left,TreeNode* right,int l){
        if(left && right){
            if(l%2){
                swap(left->val,right->val);
            }
            preorder(left->left,right->right,l+1);
            preorder(left->right,right->left,l+1);
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        preorder(root->left,root->right,1);
        return root;
    }
};