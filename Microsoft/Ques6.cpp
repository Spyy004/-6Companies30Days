class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    string getBase(int n)
    {
        switch(n){
            case 2: return "abc";
            case 3: return "def";
            case 4: return "ghi";
            case 5: return "jkl";
            case 6: return "mno";
            case 7: return "pqrs";
            case 8: return "tuv";
            case 9: return "wxyz";
        }
    }
    void solve(int a[], int n,vector<string> &res,int idx,string currString)
    {
        if(idx==n)
        {
            res.push_back(currString);
            return;
        }
        string x = getBase(a[idx]);
        for(int j=0;j<x.size();j++)
        {
            solve(a,n,res,idx+1,currString+x[j]);
        }
        return;
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> res;
        solve(a,N,res,0,"");
        return res;
    }
};
