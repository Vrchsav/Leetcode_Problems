/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
        return(NULL);
    }
    if(head->next==NULL){
        return(NULL);
    }
    int count=0;
    unordered_map<ListNode *, int> umap;
    ListNode *temp=head;
       while(temp){
        if (umap.find(temp) == umap.end()){
              umap[temp]=count;
              count++;
        }
        else{
            return(temp);
        }
           temp=temp->next;
    }
    return(NULL);

        
    }
};