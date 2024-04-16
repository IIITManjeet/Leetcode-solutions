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
    void dfs(TreeNode* root, int val,int cur, int depth){
        if(!root)return;
        if(cur==depth-2){
            TreeNode* node=root->left;
            root->left=new TreeNode(val);
            root->left->left=node;
            node=root->right;
            root->right=new TreeNode(val);
            root->right->right=node;
        }else{
            dfs(root->left,val,cur+1,depth);
        dfs(root->right,val,cur+1,depth);
        }
        return ;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        dfs(root,val,0,depth);
        return root;
    }
};