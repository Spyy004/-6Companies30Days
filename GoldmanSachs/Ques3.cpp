class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long ans = 0,i=0,j=0,prdct=1;
        while(j<n)
        {
            prdct*=a[j];
            if(prdct>=k)
            {
                while(prdct>=k && i<=j)
                {
                    prdct/=a[i];
                    i++;
                }
            }
            ans+=(j-i+1);
            j++;
        }

        return ans;
    }
};
