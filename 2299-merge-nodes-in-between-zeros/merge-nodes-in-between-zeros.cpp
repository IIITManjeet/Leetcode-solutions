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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
       ListNode* ans=new ListNode(0);
       int sum=0;
       ListNode* temp=head;
       ListNode* node=ans;
       temp=temp->next;
       while(temp!=NULL){
           while(temp->val!=0){
               sum+=temp->val;
               temp=temp->next;
           }
           node->next=new ListNode(sum);
           node=node->next;
           temp=temp->next;
           sum=0;
       }
       return ans->next;
    }
};