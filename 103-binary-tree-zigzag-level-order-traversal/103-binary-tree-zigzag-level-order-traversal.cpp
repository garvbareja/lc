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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        deque<TreeNode*> dq; dq.push_back(root); dq.push_back(nullptr);
        bool flag=true;
        vector<vector<int>> ans;
        vector<int> temp;
        while(true){
            TreeNode* front = nullptr;
            if(flag){
                front = dq.front();
                if(front){
                    dq.pop_front();
                    temp.push_back(front->val);
                    if(front->left) dq.push_back(front->left);
                    if(front->right) dq.push_back(front->right);
                }else{
                    flag=false;
                    ans.push_back(temp);
                    temp.clear();
                    if(dq.size()==1) break;
                }
            }else{
                front = dq.back();
                if(front){
                    dq.pop_back();
                    temp.push_back(front->val);
                    if(front->right) dq.push_front(front->right);
                    if(front->left) dq.push_front(front->left);
                }else{
                    flag=true;
                    ans.push_back(temp);
                    temp.clear();
                    if(dq.size()==1) break;
                }
            }
        }
        return ans;
    }
};