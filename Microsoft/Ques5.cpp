  public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<int>s;
       vector<int>ans(n,1);
       s.push(0);
       for(int i=1;i<n;i++)
       {
          while(!s.empty() && price[i]>=price[s.top()])
          {
              s.pop();
          }
          int res = s.empty()?i+1:i-s.top();
          ans[i]=res;
          s.push(i);
       }
       return ans;
    }
