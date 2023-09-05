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
int findVal(TreeNode* root) {
        return root ? root->val : 0;
    }
    int sumEvenGrandparent(TreeNode* root) {
       if (root == NULL) {
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int sum = 0;
        while(!q.empty()){
           TreeNode* curr = q.front();
           q.pop();
           if (curr->val % 2 == 0) {
                if (curr->left) {
                    sum += findVal(curr->left->left) + findVal(curr->left->right);
                }
                if (curr->right) {
                    sum += findVal(curr->right->left) + findVal(curr->right->right);
                }
            }
                        if (curr->left) 
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        } 
        return sum;
    }
};