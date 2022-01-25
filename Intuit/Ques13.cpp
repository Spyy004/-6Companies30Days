class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size(),res=0;
        vector<int>zeroes(n,0);
        for(int i=0;i<n;i++)
        {
            int ct=0;
            for(int j=m-1;j>=0;j--)
            {
                if(grid[i][j]==0)
                    ct++;
                else
                    break;
            }
            zeroes[i]=ct;
        }
        for(int i=0;i<n;i++)
        {
            if(zeroes[i]<n-1-i)
            {
                int j=i;
                while(j<n && zeroes[j]<n-1-i)j++;
                if(j==n)return -1;
                while(i<j)
                {
                    swap(zeroes[j-1],zeroes[j]);
                    res++;
                    j--;
                }
            }
        }
        return res;
    }
};
