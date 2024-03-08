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
    int dfs(TreeNode* root,int& sum){
        if(!root)return 0;
        int sumLeft=dfs(root->left,sum);
        int sumRight=dfs(root->right,sum);
        sum+=abs(sumRight-sumLeft);
        return root->val+sumLeft+sumRight;
    }
    int findTilt(TreeNode* root) {
        int sum=0;
        dfs(root,sum);
        return sum;
    }
};