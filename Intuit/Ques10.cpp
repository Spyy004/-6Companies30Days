class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited,int curr,int size)
    {
        if(visited[curr])
            return;
        visited[curr]=true;
        for(int i =0;i<size;i++)
        {
            if((!visited[i]) && (isConnected[curr][i]==1))
            {
                dfs(isConnected,visited,i,size);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(),ans=0;
        vector<bool> visited(n,0);
        for(int i =0;i<n;i++)
        {
                if(!visited[i])
                {
                    ans++;
                    dfs(isConnected,visited,i,n);
                }
        }
        return ans;
    }
};
