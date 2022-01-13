int solve(Node* root,int X, int &ct)
{
    if(!root)
    {
        return 0;
    }
    int sum = root->data + solve(root->left,X,ct)+solve(root->right,X,ct);
    if(sum==X)
    {
        ct++;
    }
    return sum;
}
int countSubtreesWithSumX(Node* root, int X)
{
    int ct=0;
	solve(root,X,ct);
	return ct;
}
