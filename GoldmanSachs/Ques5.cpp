class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int num) {
	    int n = 10000;
	    set<long long int>s;
	    s.insert(1);
	    num--;
	    while(num--)
	    {
	        auto it = s.begin();
	        long long int x = *it;
	        s.erase(it);
	        s.insert(x*2);
	        s.insert(x*3);
	        s.insert(x*5);
	    }
	    return *s.begin();
	}
};
