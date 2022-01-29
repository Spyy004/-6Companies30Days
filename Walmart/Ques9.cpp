class Solution {
public:
    int solve(int n,int l, int r,vector<vector<int>>&dp)
    {
        if(l>=r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int ans = INT_MAX;
        for(int i=l;i<=r;i++)
        {
            int l1 = solve(n,l,i-1,dp)+i;
            int l2 = solve(n,i+1,r,dp)+i;
            ans = min({ans,max(l1,l2)});
        }
        return dp[l][r]=ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n,1,n,dp);
    }
};
