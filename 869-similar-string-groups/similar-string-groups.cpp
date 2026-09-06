class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(parent[x]==x)
          return x;
        return parent[x]=find(parent[x]);  
    }

    void unite(int a,int b){
        int roota = find(a);
        int rootb = find(b);

        if(roota == rootb)
          return;

        if(rank[roota]<rank[rootb]){
            parent[roota]=rootb;
        }  
        else if(rank[rootb]<rank[roota]){
            parent[rootb]=roota;
        }
        else{
            parent[roota]= rootb;
            rank[rootb]++;
        }
    }

    bool similar(string &a,string &b){

        int diff = 0;

        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                diff++;
            }
            if(diff>2)
              return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();

        parent.resize(n);
        rank.resize(n,1);

        for(int i = 0; i<n;i++){
            parent[i]=i;
        }

        for(int i =0 ; i<n;i++){
            for(int j = i+1; j < n; j++){
                if(similar(strs[i],strs[j])){
                    unite(i,j);
                }
            }
        }

        int components = 0;

        for(int i = 0 ; i<n;i++){
            if(parent[i]==i){
                components++;
            }
        }
        return components;
    }
    
};