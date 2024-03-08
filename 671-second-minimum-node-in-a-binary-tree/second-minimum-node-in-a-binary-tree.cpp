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
    void dfs(TreeNode* root,set<int>& s){
        if(!root)return;
        s.insert(root->val);
        dfs(root->left,s);
        dfs(root->right,s);
        return;
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int>s;
        dfs(root,s);
        s.erase(*s.begin());
        return s.size()?*s.begin():-1;
    }
};