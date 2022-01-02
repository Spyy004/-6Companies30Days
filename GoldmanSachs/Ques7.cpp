#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    n=3,m=5,k=2;
    if((k+m-1)%n==0)
    {
        cout<<n<<endl;
    }
    else
    {
        cout<<(k+m-1)%n<<endl;
    }
}
