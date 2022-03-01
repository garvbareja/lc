/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root) return {};
        stack<Node*> s; vector<int> ans;
        while(root || !s.empty()){
            if(root){
                ans.push_back(root->val);
                if(root->children.size()==0) root=nullptr;
                else{
                    for(int i=root->children.size()-1;i>0;i--) s.push(root->children[i]);
                    root=root->children[0];
                }
            }else{
                root=s.top();
                s.pop();
            }
        }
        return ans;
    }
};