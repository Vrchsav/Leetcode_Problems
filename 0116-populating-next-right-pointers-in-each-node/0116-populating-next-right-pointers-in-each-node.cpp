/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        queue<Node*>q;
        q.push(root);

        Node*temp=root;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node*tt=q.front();
                q.pop();
                if(i!=n-1){
                    tt->next=q.front();
                }
                if(tt->left!=NULL){
                    q.push(tt->left);
                }
                if(tt->right!=NULL){
                    q.push(tt->right);
                }

            }

        }
        return root;
    }
};