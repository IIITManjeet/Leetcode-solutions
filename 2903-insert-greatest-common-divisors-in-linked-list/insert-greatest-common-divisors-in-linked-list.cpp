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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* cur=head;
        int prev=head->val;
        while(cur->next!=NULL){
            int b=cur->next->val;
            ListNode* temp=new ListNode(__gcd(prev,b));
            temp->next=cur->next;
            cur->next=temp;
            prev=b;
            cur=cur->next;
            cur=cur->next;
        }
        return head;
    }
};