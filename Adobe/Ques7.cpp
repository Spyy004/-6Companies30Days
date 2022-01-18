public:
    int solve(vector<int>&A,int j,int i, vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return dp[i][j]=0;
        }
        if(i==j)
        {
            return dp[i][j]=A[j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int a = A[i]+ min(solve(A,j,i+2,dp),solve(A,j-1,i+1,dp));
        int b = A[j]+ min(solve(A,j-2,i,dp),solve(A,j-1,i+1,dp));
        return dp[i][j]=max(a,b);
    }
    int maxCoins(vector<int>&A,int n)
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	    return solve(A,n-1,0,dp);
    }
