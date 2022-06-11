class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;

        int ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int size = q.size();
            long long minIndex = q.front().second;

            long long first, last;

            for(int i=0; i<size; i++)
            {
                long long newIndex = q.front().second - minIndex;
                TreeNode* node = q.front().first;
                q.pop();

                if(i==0)
                    first = newIndex;
                if(i== size-1)
                    last = newIndex;

                if(node -> left)
                    q.push({node -> left, 2*newIndex + 1});
                if(node -> right)
                    q.push({node -> right, 2*newIndex + 2});
            }

            ans = max<long long>(ans, last-first + 1);
        }

        return ans;
    }
};