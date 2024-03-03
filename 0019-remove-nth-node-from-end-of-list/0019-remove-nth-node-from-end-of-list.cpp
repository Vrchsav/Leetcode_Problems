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
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
                if (n >= count) {
            // Remove the head
            return head->next;
        }

        int sub =count-n;
        temp=head;
        while(sub-1>0){
            temp=temp->next;
            sub--;
        }
        
        
        temp->next=temp->next->next;
        return head;
    }
};