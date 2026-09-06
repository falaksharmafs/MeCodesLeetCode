class Solution {
public:
    vector<int>parent;

        int find(int x){
            if(parent[x]==x)
              return x;
            return parent[x] = find(parent[x]);  
        }

        void unite(int a ,int b){
            int roota = find(a);
            int rootb = find(b);

            if(roota==rootb)
               return;
            parent[rootb]=roota;   
        }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n+1);

        for(int i =1; i <= n; i++){
            parent[i]=i;
        }

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            if(find(u)==find(v))
               return {u,v};
            unite(u,v);   
        }
        return {};
    }
};