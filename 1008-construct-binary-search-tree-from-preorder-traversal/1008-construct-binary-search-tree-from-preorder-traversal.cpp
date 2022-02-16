class Solution {
public:
    TreeNode* maketree(vector<int>& pre,int ps,int pe,vector<int>& ngr){
        if(ps>pe) return nullptr;
        TreeNode* root=new TreeNode(pre[ps]);
        int x=ngr[ps];
        root->left=maketree(pre,ps+1,x-1,ngr);
        root->right=maketree(pre,x,pe,ngr);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        stack<int> s; vector<int> ngr(pre.size());
        for(int i=pre.size()-1;i>=0;i--)
        {
            while(!s.empty() && pre[s.top()]<=pre[i]) s.pop();
            if(s.empty()) ngr[i]=pre.size();
            else ngr[i]=s.top();
            s.push(i);
        }
        return maketree(pre,0,pre.size()-1,ngr);
    }
};