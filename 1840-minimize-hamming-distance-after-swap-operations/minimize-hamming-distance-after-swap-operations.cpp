class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b)
            return;

        if(size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    int minimumHammingDistance(
        vector<int>& source,
        vector<int>& target,
        vector<vector<int>>& allowedSwaps
    ) {

        int n = source.size();

        DSU dsu(n);

        for(auto &sw : allowedSwaps) {
            dsu.unite(sw[0], sw[1]);
        }

        vector<unordered_map<int, int>> mp(n);

        for(int i = 0; i < n; i++) {
            int root = dsu.find(i);
            mp[root][source[i]]++;
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {

            int root = dsu.find(i);

            if(mp[root][target[i]] > 0)
                mp[root][target[i]]--;
            else
                ans++;
        }

        return ans;
    }
};