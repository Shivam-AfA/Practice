// Here we use preorder traversal (NLR)
// for explanation see rightview.cpp

void f(Node* root, vector<int> &ans, int level)
{
    if(!root)
    return;

    if(level == ans.size())
    ans.push_back(root -> data);
    f(root -> left, ans, level+1);
    f(root -> right, ans, level+1);


}

vector<int> leftView(Node *root)
{
   vector<int> ans;
   f(root, ans, 0);
   return ans;
}