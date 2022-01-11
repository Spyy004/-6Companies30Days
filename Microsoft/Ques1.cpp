int dp[101][10001];
public:  
int solve(int arr[],int n,int idx,int sum,int total)
    {
        if(idx==n)
        {
            return abs((total-sum)-sum);
        }
        if(dp[idx][sum]!=-1)
        {
            return dp[idx][sum];
        }
        int take = solve(arr,n,idx+1,sum+arr[idx],total);
        int notake = solve(arr,n,idx+1,sum,total);
        return dp[idx][sum]=min(take,notake);
    }
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    memset(dp,-1,sizeof(dp));
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    return solve(arr,n,0,0,sum);
	}
