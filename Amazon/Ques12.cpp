class Solution{
    public:
    string colName (long long int n)
    {
        string ans = "";
        while(n>0)
        {
            char x = 'A'+ (n-1)%26;
            ans=x+ans;
            n=(n-1)/26;
        }
        return ans;
    }
};
