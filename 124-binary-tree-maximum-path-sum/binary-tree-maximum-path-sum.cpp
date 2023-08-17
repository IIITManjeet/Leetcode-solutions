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
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        helper(root,sum);
        return sum;
    }
private:
    int helper(TreeNode* root,int& sum){
        if(!root)return 0;
        int lsum=max(0,helper(root->left,sum));
        int rsum=max(0,helper(root->right,sum));
        sum=max(sum,lsum+rsum+root->val);
        return root->val+max(lsum,rsum);
    }
};