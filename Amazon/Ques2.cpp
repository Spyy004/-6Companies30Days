class Solution {
public:
    int longestMountain(vector<int> A) {
        int n=A.size();
        vector<int>up(n,0),down(n,0);
        for(int i=1;i<n;i++)
        {
            if(A[i]>A[i-1])
                up[i]=up[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(A[i]>A[i+1])
                down[i]=down[i+1]+1;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(up[i]&&down[i])
            {
                ans = max(ans,up[i]+down[i]+1);
            }
        }
        return ans;
    }
};
