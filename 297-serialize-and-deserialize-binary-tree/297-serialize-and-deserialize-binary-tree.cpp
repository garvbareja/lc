class Codec{
public:
    void makestring(TreeNode* root,string& res){
        if(!root){
            res.push_back('$');
            res.push_back(',');
            return;
        }
        res+=to_string(root->val); res.push_back(',');
        makestring(root->left,res);
        makestring(root->right,res);
    }
    
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res="";
        makestring(root,res);
        return res;
    }

    TreeNode* deserialize(string res){
        if(res.length()==0) return nullptr;
        TreeNode* root=nullptr;
        TreeNode* cur=nullptr;
        stack<pair<TreeNode*,bool>> s;
        for(int i=0;i<res.length();i++){
            if(res[i]=='$'){
                bool flag;
                cur=s.top().first; flag=s.top().second; s.pop();
                if(!flag) s.push({cur,true});
                i++;
            }else{
                bool flag=false;
                if(res[i]=='-'){flag=true; i++;}
                int val=0; while(res[i]!=','){val=val*10+(res[i]-'0'); i++;}
                if(flag) val*=-1;
                TreeNode* newnode = new TreeNode(val);
                if(root){
                    cur=s.top().first; flag=s.top().second; s.pop();
                    if(!flag){
                        cur->left=newnode;
                        s.push({cur,true});
                    }else{
                        cur->right=newnode;
                    }
                    s.push({newnode,false});
                }else{
                    s.push({newnode,false});
                    root=newnode;
                }
            }
        }
        return root;
    }
};
