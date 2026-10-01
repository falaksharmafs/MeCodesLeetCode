class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b)
            return false;

        if(size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];

        return true;
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(
        int n,
        vector<vector<int>>& edgeList,
        vector<vector<int>>& queries
    ) {

        sort(edgeList.begin(), edgeList.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[2] < b[2];
            });

        vector<vector<int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({
                queries[i][0],
                queries[i][1],
                queries[i][2],
                i
            });
        }

        sort(q.begin(), q.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[2] < b[2];
            });

        DSU dsu(n);

        vector<bool> ans(queries.size());

        int j = 0;

        for(auto &query : q) {

            int u = query[0];
            int v = query[1];
            int limit = query[2];
            int index = query[3];

            while(j < edgeList.size() &&
                  edgeList[j][2] < limit) {

                dsu.unite(
                    edgeList[j][0],
                    edgeList[j][1]
                );

                j++;
            }

            ans[index] =
                (dsu.find(u) == dsu.find(v));
        }

        return ans;
    }
};