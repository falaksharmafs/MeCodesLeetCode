class Solution {
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {

        unordered_map<string, int> mp;
        int id = 0;

        // Assign ID to every variable
        for(auto &eq : equations) {

            if(!mp.count(eq[0]))
                mp[eq[0]] = id++;

            if(!mp.count(eq[1]))
                mp[eq[1]] = id++;
        }

        int n = id;

        vector<vector<long double>> dist(
            n, vector<long double>(n, -1.0L)
        );

        // x / x = 1
        for(int i = 0; i < n; i++) {
            dist[i][i] = 1.0L;
        }

        // Direct equations
        for(int i = 0; i < equations.size(); i++) {

            int u = mp[equations[i][0]];
            int v = mp[equations[i][1]];

            long double value = values[i];

            dist[u][v] = value;
            dist[v][u] = 1.0L / value;
        }

        for(int k = 0; k < n; k++) {

            for(int i = 0; i < n; i++) {

                for(int j = 0; j < n; j++) {

                    if(dist[i][k] == -1 ||
                       dist[k][j] == -1)
                        continue;

                    if(dist[i][j] == -1) {
                        dist[i][j] =
                            dist[i][k] * dist[k][j];
                    }
                }
            }
        }

        vector<double> ans;

        for(auto &q : queries) {

            if(!mp.count(q[0]) ||
               !mp.count(q[1])) {

                ans.push_back(-1.0);
                continue;
            }

            int u = mp[q[0]];
            int v = mp[q[1]];

            ans.push_back((double)dist[u][v]);
        }

        return ans;
    }
};