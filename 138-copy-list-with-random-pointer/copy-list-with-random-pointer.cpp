/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        Node* itr=head;
        while(itr){
            Node* node=new Node(itr->val);
            node->next=itr->next;
            itr->next=node;
            itr=node->next;
        }
        itr=head;
        while(itr){
            if(itr->random)itr->next->random=itr->random->next;
            itr=itr->next->next;
        }
        Node* newHead=head->next;
        Node* temp=head->next;
        itr=head;
        while(itr && temp){
            Node* cur=temp->next;
            itr->next=cur;
            if(cur)temp->next=cur->next;
            itr=itr->next;
            temp=temp->next;
        }
        return newHead;
    }
};