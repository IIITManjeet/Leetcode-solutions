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
#define all(v) v.begin(), v.end()
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st(all(nums));
        ListNode* curr=new ListNode(0);
        curr->next=head;
        ListNode* tem=curr;
        while(tem->next){
            if(st.find(tem->next->val)!=st.end()){
                ListNode* delTemp=tem->next;
                tem->next=tem->next->next;
                delete delTemp;
            }else{
                tem=tem->next;
            }
        }
        return curr->next;
    }
};