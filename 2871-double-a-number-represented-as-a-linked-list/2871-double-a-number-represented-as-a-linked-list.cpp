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
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*>stt;
        ListNode* temp=head;
        ListNode* dummy =new ListNode();
        dummy->next=head;
        stt.push(dummy);
        while(temp){
            stt.push(temp);
            temp=temp->next;
        }
        int carry =0;
        while(!stt.empty()){
            int a=stt.top()->val+stt.top()->val+carry;
            stt.top()->val=a%10;
            carry=a/10;
            stt.pop();
        }
        if(dummy->val==0)
        return head;

        return dummy;
    }
};