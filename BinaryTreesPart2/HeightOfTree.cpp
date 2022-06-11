class Solution {
public:
// Here we will find the height for the left subtree and the right subtree.
//Then we will select the maximum of them and add 1 to it. (to include the root node as well)
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        int left = maxDepth(root -> left);
        // We find the left height using recursion. You can dry run and test it for better understanding.
        int right = maxDepth(root -> right);
        // Similarly we find the height of the right subtree using recursion.

        int ans = max(left,right) + 1;
        // Finding the maximum of left and right and adding 1.
        return ans;
    }
};