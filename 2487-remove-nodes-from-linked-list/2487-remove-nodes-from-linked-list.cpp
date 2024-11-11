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
        stack<ListNode*> stt;
        ListNode* temp = head;
        ListNode* sar;

        while (temp != NULL) {
            if (stt.empty()) {
                stt.push(temp);
                sar = temp;
            } else {
                while (!stt.empty() && stt.top()->val < temp->val) {
                    stt.pop();
                }
                if (stt.empty()) {
                    stt.push(temp);
                    sar = temp;

                } else {
                    stt.top()->next = temp;
                    stt.push(temp);
                }
            }
            temp=temp->next;
        }
        return sar;
    }
};
