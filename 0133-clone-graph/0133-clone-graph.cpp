/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* clone(Node*node,map<Node*,Node*>&mpp){
        if(node==NULL){
            return NULL;
        }
        Node* newnode=new Node(node->val);
        mpp[node]=newnode;
        for(auto a:node->neighbors){
            if(mpp.find(a)==mpp.end()){
                newnode->neighbors.push_back(clone(a,mpp));

            }
            else{
                newnode->neighbors.push_back(mpp[a]);
            }
        }
      return newnode;
    }
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*>mpp;
        return clone(node,mpp);

        
    }
};