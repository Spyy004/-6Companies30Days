
    int solve(vector<vector<int>> &grid,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
        {
            return 0;
        }
        grid[i][j]=0;
        int sum=0;
        sum+=solve(grid,i,j+1);
        sum+=solve(grid,i,j-1);
        sum+=solve(grid,i+1,j);
        sum+=solve(grid,i-1,j);
        sum+=solve(grid,i-1,j+1);
        sum+=solve(grid,i+1,j+1);
        sum+=solve(grid,i+1,j-1);
        sum+=solve(grid,i-1,j-1);
        return sum+1;
    }
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int x = solve(grid,i,j);
                    ans = max(ans,x);
                }
            }
        }
        return ans;
    }
