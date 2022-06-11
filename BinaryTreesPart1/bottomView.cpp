// Here we use the vertical order traversal. This means that we consider the root node forms line 0.
// The nodes to the left form lines -1, -2, -3 .........
// The nodes to the right form lines 1, 2, 3 ........
// We use queue data structure having a pair<Node*,int> to store the nodes with their line number.
// Then we create a map that has line numbers and the data of nodes in that line.
// Since we need the final element of each line, So after all nodes are traversed, we simply push the
// node datas to a vector. (We know the data in a map is automatically sorted.)

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

       // iterating through all elements of the map
       for(auto it: mp)
       ans.push_back(it.second);

       return ans;
    }
};