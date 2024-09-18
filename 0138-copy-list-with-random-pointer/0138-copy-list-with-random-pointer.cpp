/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map <Node* ,Node* >mapp;
        Node*temp=head;
        while(temp){

            mapp[temp]=new Node(temp->val);
            temp=temp->next;
        }

        for (auto x : mapp){
            if(x.first->next!=NULL){
            x.second->next=mapp[x.first->next];}
            if(x.first->random!=NULL){
            x.second->random=mapp[x.first->random];}
        } 
        return(mapp[head]);

    }
};