class Solution {
public:
    int isPossible(vector<int>&nums,int limit)
    {
        int n=nums.size(),currSum=0,splits=0;
        for(int i=0;i<n;i++)
        {
            if(currSum+nums[i]<=limit)
            {
                currSum+=nums[i];
            }
            else
            {
                splits++;
                currSum=nums[i];
            }
        }
        return splits+1;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=INT_MIN,h=0,ans=0;
        for(auto x:nums)
        {
            l=max(l,x);
            h+=x;
        }
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(isPossible(nums,mid)<=m)
            {
                h=mid-1;
                ans=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
