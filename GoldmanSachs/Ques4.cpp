string encode(string src)
{     
  int ct=1,n=src.size();
  string ans;
  for(int i=1;i<src.size();i++)
  {
      if(src[i]==src[i-1])
      {
          ct++;
      }
      else
      {
          ans.push_back(src[i-1]);
          string num = to_string(ct);
          ct=1;
          ans+=num;
      }
  }
  
      ans.push_back(src[n-1]);
      string num = to_string(ct);
      ct=1;
      ans+=num;
  return ans;
}
