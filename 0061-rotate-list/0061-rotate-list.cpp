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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0){
            return head;
        }
        ListNode* temp=head;
        ListNode*ans=NULL;
        int lenght=0;
        while(temp){
            temp=temp->next;
            lenght++;

        }
        
        k=k%lenght;

        temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        int left=lenght-k;
        while(left>1){
            left--;
            head=head->next;
            
        }
        temp=head;
        head=head->next;
        temp->next=NULL;
        cout<<head->val;
        return head;
        
    }
};