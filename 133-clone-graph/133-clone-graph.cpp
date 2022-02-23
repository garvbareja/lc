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
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> hash;
        queue<Node*> q; q.push(node);
        Node* newroot= new Node(node->val);
        hash[node]=newroot;
        while(!q.empty()){
            Node* front  = q.front(); q.pop();
            for(int i=0;i<front->neighbors.size();i++){
                if(!hash.count(front->neighbors[i])){
                    Node* newnode = new Node(front->neighbors[i]->val);
                    hash[front->neighbors[i]] = newnode;
                    q.push(front->neighbors[i]);
                }
                hash[front]->neighbors.push_back(hash[front->neighbors[i]]);
            }
        }
        return newroot;
    }
};