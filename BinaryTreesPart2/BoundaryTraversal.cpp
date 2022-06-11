void leftB(TreeNode<int>* root, vector<int> &result)
{
    TreeNode<int>* curr = root -> left;
    while(curr)
    {
        if(!(curr -> left == NULL && curr -> right == NULL))
            result.push_back(curr -> data);
        if(curr -> left)
            curr = curr -> left;
        else curr = curr -> right;
    }
}

void addLeaves(TreeNode<int>* root, vector<int> &result)
{
    if(root -> left == NULL && root -> right == NULL)
    {
        result.push_back(root -> data);
        return;
    }
    if(root -> left)
        addLeaves(root -> left, result);
    if(root -> right)
        addLeaves(root -> right, result);
}

void rightB(TreeNode<int>* root, vector<int> &result)
{
    TreeNode<int>* curr = root -> right;
    vector<int> temp;
    while(curr)
    {
        if(!(curr -> left == NULL && curr -> right == NULL))
            temp.push_back(curr -> data);
        if(curr -> right)
            curr = curr -> right;
        else curr = curr -> left;
    }

    for(int i=temp.size() - 1; i>=0; i--)
    {
        result.push_back(temp[i]);
    }
}



vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> result;
    if(!root) return result;
    if(!(root -> left == NULL && root -> right == NULL)) result.push_back(root->data);
    leftB(root,result);
    addLeaves(root,result);
    rightB(root,result);
    return result;

}