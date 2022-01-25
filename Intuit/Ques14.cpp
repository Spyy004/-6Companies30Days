class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<vector<int>>q;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j,0});
                    grid[i][j]=-1;
                }
            }
        }
        int ans=-2;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            ans=max(ans,curr[2]);
            for(int i=0;i<4;i++)
            {
                int bx = dx[i]+curr[0];
                int by = dy[i]+curr[1];
                if(bx<n && by<n && bx>=0 && by>=0 && grid[bx][by]!=-1)
                {
                    q.push({bx,by,curr[2]+1});
                   grid[bx][by]=-1;
                }
            }
        }
        return ans<=0?-1:ans;
    }
};
