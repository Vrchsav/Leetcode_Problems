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
private:
    ListNode* middleNode(ListNode* head) {
      ListNode* turtle=head;
      ListNode*  rabbit=head;
      while(rabbit && rabbit->next){
          turtle=turtle->next;
          rabbit=rabbit->next->next;
         

          
      }
      return(turtle);
    }
   
    ListNode* reverse(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* answer=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return answer;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* temp=head;
        ListNode*reverse_head=middleNode(temp );
        ListNode* reverse_h=reverse(reverse_head);
        while (reverse_h){
            if(head->val!=reverse_h->val){
              return(false);
            }
            reverse_h=reverse_h->next;
            head=head->next;

        }
        
          return true ;}
};