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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0){  
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[0]); 
        
        for (int i = 1; i < preorder.size(); i++){  
            bool done = false;  
            TreeNode* current = root;
            
            while (done == false){
                if (preorder[i] < current->val){ 
                    if (current->left == NULL){ 
                        current->left = new TreeNode(preorder[i]);
                        done = true;   
                    }
                    else{  
                        current = current->left;
                    }
                }
                else{  
                    if (current->right == NULL){ 
                        current->right = new TreeNode(preorder[i]);
                        done = true;
                    }
                    else{
                        current = current->right;   
                    }
                }
            }
        }
        
        return root;
    }
};