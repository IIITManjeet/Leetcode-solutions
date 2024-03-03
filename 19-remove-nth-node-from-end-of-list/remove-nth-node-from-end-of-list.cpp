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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // Move fast pointer n steps ahead
        for (int i = 0; i < n; ++i) {
            if (fast == nullptr) // If n is greater than or equal to the number of nodes
                return nullptr; // Return null or handle error appropriately
            fast = fast->next;
        }
        
        // Move fast to the end, maintaining the gap of n steps between slow and fast
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Delete the nth node from the end
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        
        return dummy->next;
    }
};
