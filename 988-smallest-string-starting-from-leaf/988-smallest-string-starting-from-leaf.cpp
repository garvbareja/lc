class Solution{
public:
    string smallestFromLeaf(TreeNode* r, string s = "") {
  if (r == nullptr) return "|";
  s = string(1, 'a' + r->val) + s;
  return r->left == r->right ? s : min(smallestFromLeaf(r->left, s), smallestFromLeaf(r->right, s));
}};