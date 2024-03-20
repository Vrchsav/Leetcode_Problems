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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count=0;
          ListNode* temp1=list1;
          ListNode* start=list1;
          ListNode* end=list1;
        

           while(temp1){
            temp1=temp1->next;

            count++;
            if(count==a-1){
                start=temp1;
            }
            if(count==b+1){
                end=temp1;
                break;

            }}
             temp1=list2;
            while(temp1->next){
                temp1=temp1->next;
                
            }
           cout<<start->val;
           start->next=list2;
           temp1->next=end;
           
           return list1;
    }
};