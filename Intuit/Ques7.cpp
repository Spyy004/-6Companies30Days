class Solution {
public:
    bool isPossible(int mid, vector<int> &v, int days)
    {
        int possibleInOneDay=0,currDays=1;
        for(int i =0;i<v.size();i++)
        {
            if(possibleInOneDay+v[i]>mid)
            {
                currDays++;
                possibleInOneDay=v[i];
            }
            else
                 possibleInOneDay+=v[i];
        }
        if(currDays>days)
            return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low,high=0,ans;
        for(auto x : weights)
        {
            high+=x;
        }
        if(days==1)return high;
        low = max(high/days, *max_element(weights.begin(),weights.end()));
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(isPossible(mid,weights,days))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};
