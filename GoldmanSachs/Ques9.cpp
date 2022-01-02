public:
    string printMinNumberForPattern(string S){
        string ans;
        int n=S.size();
        stack<int>st;
        int num=1;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='D')
            {
                st.push(num++);
            }
            else
            {
                st.push(num++);
                while(!st.empty())
                {
                    char c = st.top()+'0';
                    ans.push_back(c);
                    st.pop();
                }
            }
        }
        st.push(num++);
        while(!st.empty())
        {
            char c = st.top()+'0';
            ans.push_back(c);
            st.pop();
        }
        return ans;
    }
