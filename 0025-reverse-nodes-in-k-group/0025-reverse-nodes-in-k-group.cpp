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
    ListNode* K_rev(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL&&k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* kThNode=K_rev(temp,k);
            if(kThNode==NULL){
                if(prev){
                    prev->next=temp;
                }
             
                break;
            }
            ListNode* nextNode=kThNode->next;
            kThNode->next=NULL;
            reverseList(temp);
            if(temp==head){
                head=kThNode;
            }else{
                prev->next=kThNode;
            }
            prev=temp;
            temp=nextNode;
        }
        return head;
    }
};