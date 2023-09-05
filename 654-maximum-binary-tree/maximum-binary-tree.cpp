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
    // int max(vector<int>&nums,int l,int r){
    //     int maxI=l;
    //     for(int i=l;i<r;i++){
    //         if(nums[i]>nums[maxI])maxI=i;
    //     }
    //     return maxI;
    // }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums,int start,int end){
       if(start>end) return nullptr;
        int index=-1;
        int val=-1;
        for(int i=start;i<=end;i++){
            if(nums[i]>val){
                index=i;
                val=nums[i];
            }
        }
        TreeNode* root=new TreeNode(val);
        root->left=constructMaximumBinaryTree(nums,start,index-1);
        root->right=constructMaximumBinaryTree(nums,index+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums,0,nums.size()-1);
    }
};