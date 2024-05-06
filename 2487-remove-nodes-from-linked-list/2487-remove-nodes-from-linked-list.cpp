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
    ListNode* removeNodes(ListNode* head) {
        ListNode*temp=head;
        stack<ListNode*>stt;
        ListNode* hold = new ListNode(INT_MAX);
        stt.push(hold); 
        while(temp){
           
            while( !stt.empty() &&temp->val>stt.top()->val ){
                    stt.pop();

            }
            stt.push(temp);
            
            temp=temp->next;
        }
        while(stt.size()>1){
            ListNode*back=stt.top();
            stt.pop();
            stt.top()->next =back;
        }
        return hold->next;
        
    }
};