	public:
	 int find_(vector<int>& p, int v) {
        if(p[v] == -1) return v;
        else return p[v] = find_(p, p[v]);
    }
    
    void union_(vector<int>& p, vector<int>& r, int u, int v) {
        int pu = find_(p, u);
        int pv = find_(p, v);
        if(pu == pv) return;
        else {
            if(r[pu] == r[pv]) {
                p[pu] = pv;
                r[pv]++;
            }
            else if(r[pu] < r[pv]) p[pu] = pv;
            else p[pv] = pu;
        }
    }
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
         vector<int> p(V, -1), r(V, 0);
        for(int u=0; u<V; u++) {
            for(int v : adj[u]) {
                if((u == c and v == d) or (u == d and v == c)) continue;
                union_(p, r, u, v);
            }
        }
        
        if(find_(p, c) != find_(p, d)) return 1;
        return 0;
    }
