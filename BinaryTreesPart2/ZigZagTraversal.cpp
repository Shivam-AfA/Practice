class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;

        while(!q.empty())
        {
            int size = q.size();
            vector<int> row(size);
            for(int i=0; i< size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                int index = (flag) ? i : size -1 - i;

                row[index] = temp -> val;
                if(temp -> left)
                    q.push(temp -> left);
                if(temp -> right)
                    q.push(temp -> right);
            }

            flag = !flag;
            result.push_back(row);
        }
        return result;

    }
};