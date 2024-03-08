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
    void dfs(TreeNode* root,vector<int>& tree){
        if(!root)return;
        dfs(root->left,tree);
        tree.push_back(root->val);
        dfs(root->right,tree);
        return;
    }
    TreeNode* buildtree(vector<int>& inorder,int s,int e){
    if(s>e)
        return NULL;
    int mid=s+(e-s)/2;
    int ele=inorder[mid];
    TreeNode* root=new TreeNode(ele);
    root->left=buildtree(inorder,s,mid-1);
    root->right=buildtree(inorder,mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>tree;
        dfs(root,tree);
        sort(tree.begin(),tree.end());
        return buildtree(tree,0,tree.size()-1);
    }
};