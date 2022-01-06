class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        int i=0;
        vector<int>ans;
        priority_queue<pair<int,int>>q;
        while(i<k)
        {
            q.push({arr[i],i});
            i++;
        }
        ans.push_back(q.top().first);
        int idx=1;
        while(i<n)
        {
            q.push({arr[i],i});
            while(q.top().second<idx)
            {
                q.pop();
            }
            ans.push_back(q.top().first);
            i++;
            idx++;
        }
        return ans;
    }
};
