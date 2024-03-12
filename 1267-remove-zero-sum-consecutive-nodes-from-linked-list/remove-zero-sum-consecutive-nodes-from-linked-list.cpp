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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>pre;
        ListNode* temp=new ListNode(0);
        temp->next=head;
        ListNode* cur=temp;
        int presum=0;
        while(cur){
            presum+=cur->val;
            pre[presum]=cur;
            cur=cur->next;
        }
        cur=temp;
        presum=0;
        while(cur){
            presum+=cur->val;
            cur->next=pre[presum]->next;
            cur=cur->next;
        }
        return temp->next;
    }
};