class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int ans=0,i=0,n=str.length(),fl=0;
        while(i<n)
        {
            if(i==0 && str[i]=='-')
            {
                i++;
                fl=1;
                continue;
            }
            if(str[i]<'0' || str[i]>'9')
            {
                return -1;
            }
            int t=str[i]-'0';
            ans=ans*10+t;
            i++;
        }
        return fl==1?(ans*-1):ans;
    }
};
