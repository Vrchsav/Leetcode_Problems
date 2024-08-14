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
       if( head==NULL || head->next==NULL){
        return head;
       }
        ListNode *prev=NULL;
        ListNode *curr=head;
        
        ListNode *nextt=head->next;
        while(nextt){
            curr->next=prev;
            prev=curr;
            curr=nextt;
            nextt=nextt->next;
        }
        curr->next = prev;
        return curr;
        
    }
};