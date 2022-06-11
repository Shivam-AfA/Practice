// for postorder -> LRN
// for explanation, see inorder traversal

class Solution {
public:
    void postorder(TreeNode* root, vector<int> &ans)
    {
        if(root)
        {
            postorder(root -> left, ans); //L
            postorder(root -> right, ans); //R
            ans.push_back(root -> val); //N
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};