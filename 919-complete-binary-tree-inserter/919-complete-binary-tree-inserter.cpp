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
class CBTInserter {
public:
    queue<TreeNode*> q;
    TreeNode* gigachad;
    CBTInserter(TreeNode* root){
        gigachad=root;
        q.push(root);
        while(1){
            if(!q.front()->left) break;
            else q.push(q.front()->left);
            if(!q.front()->right) break;
            else{
                q.push(q.front()->right); q.pop();
            }
        }
    }
    
    int insert(int val){
        TreeNode* parent=q.front();
        TreeNode* newnode = new TreeNode(val);
        if(!parent->left) parent->left=newnode;
        else{
            parent->right=newnode;
            q.pop();
        }
        q.push(newnode);
        return parent->val;
    }
    
    TreeNode* get_root() {
        return gigachad;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */