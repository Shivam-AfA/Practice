// for preorder we use -> NLR
// for explanation, see inorder traversal

class Solution {
public:
    void preorder(TreeNode* root, vector<int> &ans)
    {
        if(root)
        {
            ans.push_back(root -> val); //N
            preorder(root -> left,ans); //L
            preorder(root -> right,ans); //R
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};