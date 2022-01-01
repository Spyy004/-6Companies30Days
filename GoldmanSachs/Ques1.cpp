class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        map<string,vector<string>>m;
        for(int i=0;i<string_list.size();i++)
        {
            string temp = string_list[i];
            sort(string_list[i].begin(),string_list[i].end());
            m[string_list[i]].push_back(temp);
        }
        vector<vector<string>>ans;
        for(auto x:m)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
