// Refer to bottom view first. The solution is same as bottom view of a binary tree.
// The only difference is that here we have put a condition for storing the values in map. So that only the
// topmost value is stored.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
       if(!root)
       return ans;

       queue<pair<Node*,int>> q;
       map<int,int> mp;

       q.push({root,0});

       while(!q.empty())
       {
           auto it = q.front();
           q.pop();

           Node* temp = it.first;
           int line = it.second;
           mp[line] = temp -> data;

           if(temp -> left)
           q.push({temp -> left, line-1});
           if(temp -> right)
           q.push({temp -> right, line+1});
       }

       for(auto it: mp)
       ans.push_back(it.second);

       return ans;
    }


};