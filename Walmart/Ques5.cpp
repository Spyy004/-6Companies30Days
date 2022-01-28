class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node* node)
    {
        if(node==NULL)return 0;
        
        if(node->left==NULL && node->right==NULL)
        {
            int t=node->data;
            node->data=0;
            return t;
        }
        
        int t=node->data;
        int l = solve(node->left);
        int r = solve(node->right);
        node->data=l+r;
        return t+l+r;
    }
    void toSumTree(Node *node)
    {
        solve(node);
    }
};
