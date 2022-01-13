string getBinary(int i)
{
    string p;
    while(i>0)
    {
        p+=to_string(i%2);
        i=i/2;
    }
    reverse(p.begin(),p.end());
    return p;
}
vector<string> generate(int N)
{
    vector<string>ans;
	for(int i=1;i<=N;i++)
	{
	    ans.push_back(getBinary(i));
	}
	return ans;
}
