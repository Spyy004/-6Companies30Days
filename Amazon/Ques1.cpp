class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        int dp[K+1][N];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=K;i++)
        {
            int prf = INT_MIN;
            for(int j=1;j<N;j++)
            {
                prf = max(prf,dp[i-1][j-1]-A[j-1]);
                dp[i][j]=max(dp[i][j-1],prf+A[j]);
            }
        }
        return dp[K][N-1];
    }
};
