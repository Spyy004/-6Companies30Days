int M = 1000000000+7;
	public:
	unordered_map<int,int>m;
	    int solve(string &str,int idx)
	    {
	        if(str.size()==idx)
	        {
	            return 1;
	        }
	        if(str[idx]=='0')
	        {
	            return 0;
	        }
	        if(m.find(idx)!=m.end())
	        {
	            return m[idx];
	        }
	        int res=solve(str,idx+1);
	        if(idx<str.size()-1 && (str[idx]=='1' || str[idx]=='2' && str[idx+1]<'7'))
	        {
	            res=(res%M+(solve(str,idx+2))%M)%M;
	        }
	        return m[idx]=res;
	    }
		int CountWays(string str){
		    return str.empty()?0:solve(str,0);
		}
