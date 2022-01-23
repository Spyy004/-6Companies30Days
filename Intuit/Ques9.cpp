class Solution {
public:
    int large = 100000;
    vector<vector<int>>ans;
    int solve(vector<vector<int>>&heights,vector<vector<bool>>&v,int i, int j, int curr,int x,int y, int yes)
    {
        if(i<0 || j<0)
        {
            if(yes==true)
                ans.push_back({x,y});
        }
        if(i>=heights.size() || j>=heights[0].size())
            return 1;
        if(v[i][j] || curr<heights[i][j])
            return large;
        v[i][j]=true;
        int l = solve(heights,v,i,j-1,heights[i][j]);
        int r = solve(heights,v,i,j+1,heights[i][j]);
        int u = solve(heights,v,i-1,j,heights[i][j]);
        int d = solve(heights,v,i+1,j,heights[i][j]);
        v[i][j]=false;
        if(l+r+u+d==0)
            return 0;
        return large;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(),m=heights[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(solve(heights,visited,i,j,heights[i][j],i,j,false)==0)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
