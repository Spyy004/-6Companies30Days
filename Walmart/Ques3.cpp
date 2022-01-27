class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size(),ac=0,bc=0,ct=0;
        int i=0,j=0;
        while(i<n)
        {
            if(colors[i]=='A')
                ct++;
            else
            {
                if(ct>=3)
                {
                    ac+=ct-2;
                }
                ct=0;
            }
            i++;
        }
        if(ct>=3)
        {
            ac+=ct-2;
        }
        ct=0;
        while(j<n)
        {
            if(colors[j]=='B')
                ct++;
            else
            {
                if(ct>=3)
                {
                    bc+=ct-2;
                }
                ct=0;
            }
            j++;
        }
        if(ct>=3)
        {
            bc+=ct-2;
        }
        ct=0;
       // cout<<ac<<" "<<bc<<endl;
        if(ac>bc)return true;
        return false;
    }
};
