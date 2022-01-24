class Solution {
public:
    Node* connect(Node* root) {
        Node* res = root;
        while(root){
            Node* nxt = root->left;
            while(root){
                if(root->left) root->left->next = root->right;
                if(root->next && root->right) root->right->next = root->next->left;
                root=root->next;
            }
            root=nxt;
        }
        return res;
    }
};