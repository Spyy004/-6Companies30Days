int m = (N.size())/2 - 1;
bool flag = 0;
for(int i = m-1 ;i>=0 ;i--)
{
  if(N[i] < N[i+1])
  {
    flag = 1;
    break ;
  }
}
if(flag ==0)
  {
    return "-1";
  }
m+=1;
next_permutation(N.begin(), N.begin() + m);
int i=0;
int j=N.size()-1;
while(i < j){
  N[j] = N[i];
  i++;
  j--;
}
return N;
