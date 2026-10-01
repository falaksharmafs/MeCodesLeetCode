class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 1; i <= n; i++)
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);

        int used = 0;

        for(auto &e : edges){
            if(e[0] == 3){
                bool a = alice.unite(e[1],e[2]);
                bool b = bob.unite(e[1],e[2]);

                if(a||b)
                  used++;
            }
        }

        for(auto &e : edges){
            if(e[0]==1){
                bool a = alice.unite(e[1],e[2]);

                if(a)
                  used++;
                
            }
        }

        for(auto &e : edges){
            if(e[0]==2){
                bool b = bob.unite(e[1],e[2]);
                

                if(b)
                  used++;
            }
        }

        for(int i = 2; i <= n ;i++){
            if(alice.find(i) != alice.find(1))
               return -1;
            if(bob.find(i) != bob.find(1))
               return -1;   
        }
        return edges.size() - used;
    }
};