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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        queue<Node*> q; q.push(root); vector<vector<int>> res; vector<int> temp;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                Node* front=q.front(); q.pop();
                temp.push_back(front->val);
                for(int i=0;i<front->children.size();i++) q.push(front->children[i]);
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};