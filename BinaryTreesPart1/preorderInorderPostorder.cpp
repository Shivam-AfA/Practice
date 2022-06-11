void solve(BinaryTreeNode<int> *root,vector<int> &ans0,vector<int> &ans1,vector<int> &ans2)
{
    if(root == NULL)
        return;

    // Here for each traversal we have used the basics.
    // we know for preorder we use NLR. and here we are getting NLR(ans1). pushing to ans0 or ans2 does not
    // affect this process.
    // Similarly for inorder we are getting LNR(ans0) and for postorder LRN(ans2).

    ans1.push_back(root->data); //N
    solve(root->left,ans0,ans1,ans2); //L
    ans0.push_back(root->data);
    solve(root->right,ans0,ans1,ans2); //R
    ans2.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){

    vector<vector<int>> ans;
    vector<int> ans1,ans2,ans0;
    solve(root,ans0,ans1,ans2);
    ans.push_back(ans0);
    ans.push_back(ans1);
    ans.push_back(ans2);
    return ans;

}
