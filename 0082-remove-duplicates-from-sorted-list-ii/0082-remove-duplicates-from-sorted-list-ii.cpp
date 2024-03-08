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
    ListNode* deleteDuplicates(ListNode* head) {
   
        ListNode *dummy=new ListNode(-1,head);
        ListNode*temp=dummy;
        ListNode*temp2=head;

        int current_val=-10;

        while(temp2!=NULL){
            if(current_val==temp2->val){
                temp2=temp2->next;
                if(temp2==NULL){
                    temp->next=NULL;
                }
            }
            else{
                if(temp2->next!=NULL && temp2->next->val == temp2->val){
                    current_val=temp2->val;
                }
                else{
                    temp->next=temp2;
                    current_val=temp2->val;
                    temp=temp->next;

                }
             temp2=temp2->next;   
            }
        }
        return dummy->next;
    }
};