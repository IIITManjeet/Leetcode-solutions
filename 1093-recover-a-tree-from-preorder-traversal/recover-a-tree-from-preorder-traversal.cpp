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
    TreeNode* recoverFromPreorder(string s) {
        stack<TreeNode*>st;
        for(int i=0;i<s.size();){
            int level=0;
            while(s[i]=='-'){
                level++;
                i++;
            }
            int start=i;
            while(isdigit(s[i]))i++;
            int val=stoi(s.substr(start,i-start+1));
            // cout<<val<<"level:"<<level<<endl;
            TreeNode* temp=new TreeNode(val);
            if(st.empty()){st.emplace(temp);continue;}
            while(st.size()>level)st.pop();
            if(st.top()->left)st.top()->right=temp;
            else st.top()->left=temp;
            st.emplace(temp);
        }
        while(st.size()>1)st.pop();
        return st.top();
    }
};