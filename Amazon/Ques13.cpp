class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size(),m=mat[0].size();
        vector<int>dir = {0,1,0,-1,0};
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<int,int>>q; // queue for bfs
        for(int i = 0;i<n;i++) 
        {
            for(int j = 0;j<m;j++)
            {
               if(mat[i][j]==2) // process the already rotten oranges first
               {
                   mat[i][j]=0;  
                   q.push({i,j});
               }
                else if(mat[i][j]==1) // fresh oranges are assigned a random number greater than 2. It will act as an initial time
                    mat[i][j]=1000;
                else
                    mat[i][j]=INT_MAX;  // empty cells are assigned INT_MAX
            }
        }
        int maxi = 0;
        while(!q.empty())
        {
            pair<int,int>p1 = q.front();
            maxi = mat[p1.first][p1.second];
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int x = p1.first + dir[i];
                int y = p1.second + dir[i+1];
                if(x<0 || x==n || y<0 || y==m || mat[x][y]==INT_MAX || mat[x][y]!=1000)continue; // skipping boundary cases and empty cells
                    mat[x][y] = mat[p1.first][p1.second]+1; 
                    q.push({x,y}); 
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j]==1000)  // if any cell is still fresh, return -1
                    return -1;
            }
        }
      return maxi;
    }
};
