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
    int max(vector<int>&nums,int l,int r){
        int maxI=l;
        for(int i=l;i<r;i++){
            if(nums[i]>nums[maxI])maxI=i;
        }
        return maxI;
    }
    TreeNode* construct(vector<int>&nums,int l,int r){
        if(l==r)return nullptr;
        int maxEle=max(nums,l,r);
        TreeNode* root=new TreeNode(nums[maxEle]);
        root->left=construct(nums,l,maxEle);
        root->right=construct(nums,maxEle+1,r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums,0,nums.size());
    }
};