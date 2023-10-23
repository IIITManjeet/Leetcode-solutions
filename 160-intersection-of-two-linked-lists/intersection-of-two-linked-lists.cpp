class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA){
            ListNode* temp=headB;
            while(temp){
                if(temp==headA){
                    return headA;
                }
                temp=temp->next;
            }
            headA=headA->next;
        }
        return NULL;
    }
};