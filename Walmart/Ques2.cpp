class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>g[n];
        int i=0;
        for(auto x:edges)
        {
            g[x[0]].push_back({x[1],succProb[i]});
            g[x[1]].push_back({x[0],succProb[i]});
            i++;
        }
        vector<bool>v(n,false);
      //  return solve(n,g,start,v,end);
        priority_queue<pair<double,int>>q;
        vector<double>ans(n,0.0000);
        q.push({1.0000,start});
        while(!q.empty())
        {
            auto curr = q.top();
            q.pop();
            if(!v[curr.second])
            {
                v[curr.second]=true;
                for(auto x:g[curr.second])
                {
                    if(ans[x.first]<curr.first*x.second)
                    {
                        ans[x.first]=curr.first*x.second;
                        q.push({ans[x.first],x.first});
                    }
                }
            }
        }
        return ans[end];
    }
};
