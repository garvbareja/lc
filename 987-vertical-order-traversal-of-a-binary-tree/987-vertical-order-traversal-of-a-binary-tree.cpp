/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static bool custom(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root){
        queue<pair<TreeNode*,int>> q; q.push({root,0});
        map<int,vector<pair<int,int>>> hash;
        vector<vector<int>> ans;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode* front = q.front().first;
                int x = q.front().second; q.pop();
                hash[x].push_back({level,front->val});
                if(front->left) q.push({front->left,x-1});
                if(front->right) q.push({front->right,x+1});
            }
            level++;
        }
        for(auto it=hash.begin();it!=hash.end();it++){
            sort(it->second.begin(),it->second.end(),custom);
            vector<int> temp;
            for(int i=0;i<it->second.size();i++){
                temp.push_back(it->second[i].second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};