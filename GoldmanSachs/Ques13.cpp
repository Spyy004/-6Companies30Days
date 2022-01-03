 string solve(string s, int &pos)
    {
        int num = 0;
        string word="";
        for(;pos<s.size();pos++)
        {
            if(s[pos]=='[')
            {
                string curr = solve(s,++pos);
                while(num>0)
                {
                    word+=curr;
                    num--;
                }
            }
            else if(s[pos]>='0' && s[pos]<='9')
            {
                num = num*10 + s[pos]-'0';
            }
            else if(s[pos]==']')
                return word;
            else
                word+=s[pos];
        }
        return word;
    }
    string decodedString(string s){
        int idx = 0;
        return solve(s, idx);
    }
