class Solution {
public:
    unordered_map<int,int> hash;
    TreeNode* buildtree(vector<int>& pre,int pres,int pree,vector<int>& post,int posts,int poste){
        if(pres>pree || posts>poste) return nullptr;
        TreeNode* root = new TreeNode(pre[pres]);
        if(pres==pree || posts==poste) return root;
            int nleft = hash[post[poste-1]]-pres-1;
            root->left = buildtree(pre,pres+1,pres+nleft,post,posts,posts+nleft-1);
            root->right = buildtree(pre,pres+nleft+1,pree,post,posts+nleft,poste-1);
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post){
        for(int i=0;i<pre.size();i++) hash[pre[i]]=i;
        return buildtree(pre,0,pre.size()-1,post,0,post.size()-1);
    }
};