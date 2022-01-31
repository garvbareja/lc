class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* front= root;
        while(front){
            if((p->val<front->val && q->val>front->val) || (q->val<front->val && p->val>front->val)) return front;
            if(front==p) return p;
            if(front==q) return q;
            if(p->val<front->val && q->val<front->val) front = front->left;
            else front = front->right;
        }
        return front;
    }
};