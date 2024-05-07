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
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    ListNode* doubleIt(ListNode* head) {
        if(!head)return head;
        head=reverseList(head);
        ListNode* cur=head;
        ListNode* newH=nullptr;
        int carry=0;
        while(cur!=nullptr){
            int val=cur->val*2+carry;
            carry=val/10;
            val%=10;
            if(newH==nullptr){
                newH=new ListNode(val);
            }
            else{
                  ListNode* newN=new ListNode(val);
                newN->next=newH;
                newH=newN;
            }
            cur=cur->next;
        }
        if(carry){
            ListNode* newN=new ListNode(carry);
            newN->next=newH;
            newH=newN;
        }
        return newH;
    }
};