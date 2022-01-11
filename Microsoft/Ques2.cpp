public:
    bool dfs(int N, vector<int>g[],vector<bool>&visited,vector<bool>&smallvisited,int curr)
    {
        visited[curr]=true;
        smallvisited[curr]=true;
        for(auto x:g[curr])
        {
            if(visited[x]==false)
            {
                if(dfs(N,g,visited,smallvisited,x))
                {
                    return true;
                }
            }
            else if(visited[x]==true && smallvisited[x]==true)
            {
                return true;
            }
        }
        smallvisited[curr]=false;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int>g[N];
	    for(auto &x:prerequisites)
	    {
	        g[x.second].push_back(x.first);
	    }
	    vector<bool>visited(N,false),smallvisited(N,false);
	    for(int i=0;i<N;i++)
	    {
	        if(visited[i]==false)
	        {
	            if(dfs(N,g,visited,smallvisited,i))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}
