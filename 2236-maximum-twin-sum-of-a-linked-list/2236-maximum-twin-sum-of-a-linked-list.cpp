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

    ListNode* rev(ListNode* h)
    {
        if(!h or !h->next)
        {
            return h;
        }
        ListNode* curr = h, *nxt = NULL, *prev = NULL;
        while(curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode* p = head;
        while(p)
        {
            v.push_back(p->val);
            p=p->next;
        }
        ListNode* rh = rev(head);
        int i = 0;
        while(rh)
        {   
            v[i] += rh->val;
            i++;
            rh=rh->next;
        }
        int mx = INT_MIN;
        for(auto i: v)
        {
            mx = max(mx,i);
        }
        return mx;

   }
};