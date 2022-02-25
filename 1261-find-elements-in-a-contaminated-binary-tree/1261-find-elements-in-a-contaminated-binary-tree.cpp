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
class FindElements {
public:
    unordered_set<int> seen;
    void dfs(TreeNode* root,int x){
        if(!root) return;
        seen.insert(x);
        dfs(root->left,(2*x)+1); dfs(root->right,(2*x)+2);
    }
    
    FindElements(TreeNode* root) {
        seen.insert(0);
        dfs(root->left,1); dfs(root->right,2);
    }
    
    bool find(int target) {
        return seen.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */