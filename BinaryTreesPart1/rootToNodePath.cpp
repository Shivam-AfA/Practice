
bool recurse(TreeNode* root, int x, vector<int> &ans)
 {
     if(!root)
     return false;

     ans.push_back(root -> val);

     if(root -> val == x)
     return true;

     if(recurse(root -> left, x, ans) || recurse(root -> right, x, ans))
     return true;

     ans.pop_back();
     return false;
 }


vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;

    if(!A)
    return ans;

    recurse(A,B,ans);
    return ans;
}
