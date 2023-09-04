/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeParent(TreeNode* node,unordered_map<TreeNode*,TreeNode*>& parentCheck){
        if(!node)return;
         if(node->left){
                parentCheck[node->left]=node;
                
            }
            if(node->right){
                parentCheck[node->right]=node;
            }
            makeParent(node->left,parentCheck);
            makeParent(node->right,parentCheck);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentCheck;
        makeParent(root,parentCheck);
        vector<int>ans;
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        q.push(target);
        vis[target]=true;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            if(level++==k)break;
            for(int i=0;i<size;i++){
            TreeNode* temp=q.front();q.pop();
            if(temp->left && !vis[temp->left]){
                q.push(temp->left);
                vis[temp->left]=true;
            }
            if(temp->right && !vis[temp->right]){
                q.push(temp->right);
                vis[temp->right]=true;
            }
            if(parentCheck[temp] && !vis[parentCheck[temp]]){
                q.push(parentCheck[temp]);
                vis[parentCheck[temp]]=true;
            }
            }
        }
        while(!q.empty()){
            TreeNode* temp=q.front();q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};