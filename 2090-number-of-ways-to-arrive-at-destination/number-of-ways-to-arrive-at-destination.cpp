class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const long long M = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);

        for(auto r : roads){
            int u = r[0];
            int v = r[1];
            int w = r[2];

            //since its bi-directional

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});


        }

        vector<long long>dist(n,1e18);
        vector<long long>ways(n,0);

        priority_queue<pair<long long,int>,vector<pair<long long,int>> , greater<pair<long long , int>>> pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0,0});

        while(!pq.empty()){

            auto[d,u] = pq.top();
            pq.pop();

            if(d != dist[u])
              continue;

            for(auto [v,w] : adj[u]){
                long long newdist = d + w;

                if(newdist < dist[v]){
                    dist[v] = newdist;
                    ways[v] = ways[u];

                    pq.push({dist[v],v});
                }
                else if(newdist == dist[v]){
                    ways[v] = (ways[u] + ways[v]) % M;
                }

            }  
        }

        return ways[n-1];
        
    }
};