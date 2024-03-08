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

    int parentA = -1,parentB = -1,levelA = -1,levelB = -1;
    void dfs(TreeNode* root,int level,int parent,int x,int y){
        if(root==NULL) return;
        dfs(root->left,level+1,root->val,x,y);
        if(root->val==x){
            parentA = parent;
            levelA = level;
        }
        else if(root->val==y){
            parentB = parent;
            levelB = level;
        }
        dfs(root->right,level+1,root->val,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        bool flag=false;
        int level = 0,parent = -1;
        dfs(root,level,parent,x,y);
        if(levelA==levelB && parentA!=parentB) return true;
        return false;
    }
};