 bool canPair(vector<int> nums, int k) {
        map<int,int>m;
       
        int n = nums.size();
        if(n%2!=0)
        {
            return false;
        }
        if(k==1)
        {
            return true;
        }
        for(int i=0;i<n;i++)
        {
            m[nums[i]%k]++;
        }
        int i=1,j=k-1;
        if(m[0]%2!=0)
        {
            return false;
        }
        while(i<=j)
        {
            if(m[i]!=m[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
