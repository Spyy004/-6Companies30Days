 long long int sum=0;
        int i=0,j=0;
        while(j<n)
        {
            sum+=arr[j];
            while(sum>s)
            {
                sum-=arr[i];
                i++;
            }
            if(sum==s)
            {
                return {i+1,j+1};
            }
            j++;
        }
        return {-1};
