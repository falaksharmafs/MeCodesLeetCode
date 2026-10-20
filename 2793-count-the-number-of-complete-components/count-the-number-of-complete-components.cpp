class Solution {

    vector<int>parent,size;

    int find(int x){
        if(parent[x]==x)
           return x;
        return parent[x] =find(parent[x]);  
    }

    void unite(int a,int b){
        a = find(a);
        b = find(b);

        if(a==b)
            return;
        if(size[a]<size[b])
            swap(a,b);    

        parent[b]=a;
        size[a]+=size[b];    
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n,1);

        for(int i =0; i<n;i++){
            parent[i]=i;
        }
        for(auto &edge:edges){
            unite(edge[0],edge[1]);
        }

        //counting the number of edges in each of the componenets here


        vector<int> edgecount(n,0);


        for(auto &edge : edges){
            int root = find(edge[0]);
            edgecount[root]++;
        }
        int ans = 0;

        for(int i =0; i<n;i++){
            if(find(i) != i){
                continue;
            }

            int vertices = size[i];
            int req = vertices * ( vertices - 1)/2;

            if(edgecount[i] == req)
                ans++;
        }

        return ans;
    }
};