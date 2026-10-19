class Solution {

    vector<int>parent,size;

    int find(int x){
        if(parent[x]==x)
          return x;
        return parent[x]=find(parent[x]);  
    }

    bool unite(int a,int b){
        a = find(a);
        b = find(b);

        if(a==b)
           return false;

        if(size[a]<size[b]){
            swap(a,b);
        }   

        parent[b]=a;
        size[a] +=size[b];

        return true;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
           return -1;

        parent.resize(n);
        size.resize(n,1);


        for(int i = 0;i<n;i++)
           parent[i]=i;
        for(auto &edge : connections){
            unite(edge[0],edge[1]);
        }      

        int components = 0;

        for(int i = 0; i < n;i++){
            if(find(i)==i)
                 components++;
        }

        return components-1;
    }
};