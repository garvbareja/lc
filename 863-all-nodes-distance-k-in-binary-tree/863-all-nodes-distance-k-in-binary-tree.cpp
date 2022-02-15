class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    unordered_set<TreeNode*> vis;
    vector<int> ans;
    void makeparents(TreeNode* root,TreeNode* prev){
        if(!root) return;
        if(prev) parent[root]=prev;
        makeparents(root->left,root);
        makeparents(root->right,root);
    }
    
    bool bfs(TreeNode* target,int k){
        vis.insert(target);
        queue<TreeNode*> q; q.push(target);
        while(!q.empty() && k){
            int size=q.size();
            while(size--){
                TreeNode* front = q.front(); q.pop();
                if(front->left && !vis.count(front->left)){
                    q.push(front->left);
                    vis.insert(front->left);
                }
                if(front->right && !vis.count(front->right)){
                    q.push(front->right);
                    vis.insert(front->right);
                }
                if(parent.count(front) && !vis.count(parent[front])){
                    q.push(parent[front]);
                    vis.insert(parent[front]);
                }
            }k--;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return k==0;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeparents(root,nullptr);
        if(bfs(target,k)) return ans;
        return {};
    }
};