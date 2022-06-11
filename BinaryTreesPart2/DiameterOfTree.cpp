// The solution becomes a bit tricky while optimising. This is not the brute force solution.
// This is the optimised solution.
// Here we use the same function that we used to find the height of tree.
// We know that Diameter is the longest distance between 2 leaf nodes in a tree. It may or may not pass through the root.
// So all we need to do is that we want to maximise (leftHeight + rightHeight).

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // Considering the diameter initially as 0
        int diameter =0;
        // Create the height function with two arguments (since we are calculationg height and simultaneously
        // updating the diameter.)
        height(root,diameter);
        return diameter;
    }

    int height(TreeNode* root, int& diameter)
    {
         if(root == NULL)
             return 0;

        int left = height(root -> left, diameter);
        int right = height(root -> right,diameter);

        // For each node, diameter is updated with the maximum value.
        diameter = max(diameter, left + right);

        // We return the height for each node to check for the correct diameter.
        return 1+ max(left,right);
    }
};