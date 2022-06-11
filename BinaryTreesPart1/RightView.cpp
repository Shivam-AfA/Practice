// GFG code
// In this code we have used reverse Preorder Traversal (NRL)
// Here we have used two inputs mainly, root and level.
// The concept is that when we move towards the right side from the root, the first element that shall be
// processed should be pushed to the answer vector.
// We know that for every level, we have to choose the rightmost element. So while moving right, we
// compare the size of the vector and the value of the level. If both are same, we push the node into the
// vector.
// So even when the process goes to the left subtree, only that element will be added whose level has still
// not been processed.

void f(Node* root, vector<int> &ans, int level)
{
    if(!root)
    return;

    // Comparison of level and size of vector.
    if(level == ans.size())
    ans.push_back(root -> data); //N

    f(root -> right, ans, level+1); //R

    f(root -> left, ans, level+1);// L


}

vector<int> leftView(Node *root)
{
   vector<int> ans;
   f(root, ans, 0);
   return ans;
}