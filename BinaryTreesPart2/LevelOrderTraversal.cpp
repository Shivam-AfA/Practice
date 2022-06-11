class Solution {
public:
// Here we are given a tree. We have to traverse through the tree level by level.
// WE have to return a 2D vector.
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        // if root is null, we'll return empty vector.
        vector<vector<int>> result;
        // we create a 2D vector that we'll return.
        queue<TreeNode*> q;
        // We use the queue data structure here.
        q.push(root);
        // We'll push the root node into the queue at the start.
        // q.push(NULL);

        while(!q.empty())
        {
            int count = q.size();
            // We will iterate through the queue for each level.
            vector<int> levelNodes;
            // Here we create a 1D vector that we will push to the 2D vector.
            for(int i=0; i< count; i++)
            {
                TreeNode* temp = q.front();
                // Here we create a temporary TreeNode pointer that will store the node whose value we have to push into the 1D vector.
            q.pop();
            //Now we remove the element from the queue for further operations.

            // if(temp == NULL)
            levelNodes.push_back(temp -> val);
            // Now we push the data of the node that we stored in the temporary pointer.
            if(temp -> left)
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp -> right);
            // Here we check if the node has left or right elements, if yes, we push them into the queue, and for loop agains begins.
            }

            result.push_back(levelNodes);
            // Here we push the 1D vector into the 2D vector for each level. And this step is repeated until queue becomes empty.
        }

        return result;
        }
};