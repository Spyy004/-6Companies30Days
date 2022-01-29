class Solution{
public:
    int height(int N){
        int sum=0,ans=0,i=1;
        while(sum<N)
        {
            sum+=i;
            i++;
            ans++;
        }
        if(sum==N)return ans;
        return ans-1;
    }
};
