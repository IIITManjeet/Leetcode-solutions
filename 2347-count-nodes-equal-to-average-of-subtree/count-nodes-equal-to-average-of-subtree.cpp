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
    pair<int,int> dfs(TreeNode* root, int& result){
        if(root==NULL)return {0,0};
        auto [leftSum,leftCount]=dfs(root->left,result);
        auto [rightSum,rightCount]=dfs(root->right,result);
        int sum = root->val+leftSum+rightSum;
        int count=1+leftCount+rightCount;
        if(sum/count==root->val)result++;
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        int result=0;
        dfs(root,result);
        return result;
    }
};