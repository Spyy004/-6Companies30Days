class Solution {
public:
    bool solve(vector<int>& piles, int h, int mid)
    {
        int sum=0;
        for(int i=0;i<piles.size();i++)
        {
            if(mid!=0 && piles[i]%mid==0)
                sum+=piles[i]/mid;
            else if(mid!=0)
                sum+=(piles[i]/mid)+1;
        }
        if(sum>h)
            return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int hours) {
    
        int l = 1, h= *max_element(piles.begin(),piles.end()),ans=0;
        while(l<=h)
        {
            int m = l+(h-l)/2;
            if(solve(piles,hours,m))
            {
                h=m-1;
                ans=m;
            }
            else
                l=m+1;
        }
        return ans;
    }
};
