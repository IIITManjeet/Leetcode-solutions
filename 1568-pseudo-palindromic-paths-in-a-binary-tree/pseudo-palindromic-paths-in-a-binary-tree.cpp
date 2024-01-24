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
    void pseudo_count(TreeNode* root,vector<int>& n,int& cnt){
        if(root==NULL)return;
        n[root->val]++;
        pseudo_count(root->left,n,cnt);
        pseudo_count(root->right,n,cnt);
        if(root->left==NULL&&root->right==NULL){
            int f=0;
            for(int i=1;i<=9;i++){
                if(n[i]%2!=0)f++;
            }
            if(f==1||f==0){
                cnt++;
            }
        }
        n[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt=0;
        vector<int>n(10,0);
        pseudo_count(root,n,cnt);
        return cnt;
    }
};