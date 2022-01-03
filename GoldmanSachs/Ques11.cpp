public:
    int *findTwoElement(int *arr, int n) {
        int *ans = new int[2];
        for(int i=0;i<n;i++)
        {
            int k = abs(arr[i])-1;
            if(arr[k]>0)
            {
                arr[k]= -arr[k];
            }
            else
            {
                ans[0]=k+1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                ans[1]=i+1;
            }
        }
        return ans;
    }
