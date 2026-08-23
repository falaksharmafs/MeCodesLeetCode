class Solution {
public:
    bool topocheck(unordered_map<int,vector<int>>&adj,int n,vector<int>&indegree){
        queue<int>que;
        int count = 0;
        for(int i = 0 ; i<n; i++){
            if(indegree[i]==0){
              count++;
              que.push(i);
            }
        }
        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int &v : adj[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    count++;
                    que.push(v);
                }
            }
        }
        if(count == n) /// hence we gonna be able to visit and compelete all courses
          return true;
        return false; // saare courses nahi hue , we gonna have afced a loop henceforth soehere ineteween 

    }
    bool canFinish(int numCourses, vector<vector<int>>& prere) {
        
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0); ///kahn's algo

        for(auto &vec : prere){
            int a = vec[0];
            int b = vec[1];
            ///b------>a
            adj[b].push_back(a);
            ///incremnet bhi a ka hi hoga indegree main, haina
            indegree[a]++;
        }

        // also we need to check aroun whther this stuff has any cycle around ,fail case

        return topocheck(adj,numCourses,indegree);
    }
};