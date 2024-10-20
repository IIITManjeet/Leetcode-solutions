class Solution {
public:
    int f(TreeNode* root,int& ans){
        if(root==NULL)return 1;
        int r=f(root->right,ans);
        int l=f(root->left,ans);
        if(r==0 || l==0){
            ans++;
            return 2;
        }
        if(r==2 || l==2){
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int ans=0;
        if(f(root,ans)==0)ans++;
        return ans;
    }
};