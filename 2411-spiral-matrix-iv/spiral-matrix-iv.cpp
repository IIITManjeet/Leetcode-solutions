/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//  class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         vector<int>arr;
//         int top=0,bottom=matrix.size()-1,left=0,right=matrix[0].size()-1;
//         if(matrix.empty()){
//             return arr;
//         }
//         while(top<=bottom&&left<=right){
//             for(int i=left;i<=right;i++){
//                 arr.push_back(matrix[top][i]);
//             }
//             top++;
//             for(int i=top;i<=bottom;i++){
//                 arr.push_back(matrix[i][right]);
//             }
//             right--;
//             if(top<=bottom){
//                 for(int i=right;i>=left;i--){
//                     arr.push_back(matrix[bottom][i]);
//                 }
//                 bottom--;
//             }
//             if(left<=right){
//                 for(int i=bottom;i>=top;i--){
//                     arr.push_back(matrix[i][left]);
//                 }
//                 left++;
//             }
//         }
//         return arr;
        
//     }
// };
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int top=0;
        int left=0;
        int right=n-1;
        int bottom=m-1;
        while(top<=bottom&&left<=right){
            for(int i=left;i<=right&&head!=NULL;i++){
                ans[top][i]=head->val;
                head=head->next;
            }
            top++;
            for(int i=top;i<=bottom&&head!=NULL;i++){
              ans[i][right]=head->val;
              head=head->next;
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left&&head!=NULL;i--){
                    ans[bottom][i]=head->val;
                    head=head->next;
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top&&head!=NULL;i--){
                    ans[i][left]=head->val;
                    head=head->next;
                }
                left++;
            }
        }
        return ans;
    }
};