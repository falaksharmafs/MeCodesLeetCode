class Solution {
public:

    int findCheapestPrice(int n,
                          vector<vector<int>>& flights,
                          int src,
                          int dst,
                          int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto f : flights) {

            int u = f[0];
            int v = f[1];
            int wt = f[2];

            adj[u].push_back({v, wt});
        }

        vector<vector<int>> dist(
            n, vector<int>(k + 2, 1e9)
        );

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        // cost, node, stops
        pq.push({0, src, 0});

        dist[src][0] = 0;

        while(!pq.empty()) {

            auto [cost, u, stops] = pq.top();
            pq.pop();

            if(u == dst)
                return cost;

            if(stops > k)
                continue;

            for(auto [v, wt] : adj[u]) {

                int newCost = cost + wt;
                int newStops = stops + 1;

                if(newCost < dist[v][newStops]) {

                    dist[v][newStops] = newCost;

                    pq.push({
                        newCost,
                        v,
                        newStops
                    });
                }
            }
        }

        return -1;
    }
};