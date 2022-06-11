// Since here we cannot print the output using cout, we have to create a separate function which contains
// the implementaion of inorder traversal. In this function, we'll modify the vector that will be returned
// by the already given function.

// For inorder, we use LNR.


class Solution {
public:
// This is the function that we have to create
    void inorder(TreeNode* root, vector<int> &ans)
    {
        if(root != NULL)
        {
            // We traverse to the left of all the nodes first.
            inorder(root -> left,ans); //L
            // Then we push the value of the nodes into the vector.
            ans.push_back(root -> val); //N
            // Then the same step for the right of all nodes.
            inorder(root -> right,ans); //R

        }
    }

// This is the already given function.
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};