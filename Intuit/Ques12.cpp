class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inorder(numCourses,0);
        vector<int>outorder(numCourses,0);
        vector<int>g[numCourses];
         for(auto x:prerequisites)
        {
            g[x[0]].push_back(x[1]);
            inorder[x[1]]++;
            outorder[x[0]]++;
        }
        vector<int>ans;
        queue<int>topo;
        for(int i=0;i<numCourses;i++)
        {
            if(inorder[i]==0)
            {
                topo.push(i);
            }
        }
        while(!topo.empty())
        {
            int curr = topo.front();
            topo.pop();
            ans.push_back(curr);
            for(auto x:g[curr])
            {
                inorder[x]--;
                if(inorder[x]==0)
                {
                    topo.push(x);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()!=numCourses)
            return {};
        return ans;
    }
};
