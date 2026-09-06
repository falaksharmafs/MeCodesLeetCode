class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prs, vector<vector<int>>& qs) {
        //reachablilty matrix

        vector<vector<bool>>reachable(n,vector<bool>(n,false));

        //dwelling from prerequisites
        //direct equalities

        for(auto &p :prs){
            int u = p[0];
            int v = p[1];

            reachable[u][v] = true;
        }

        //now with flloyd warshall
        //indirect equalities

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n ;i++){
                for(int j = 0; j < n; j++){
                    reachable[i][j] = reachable[i][j]||(reachable[i][k] && reachable[k][j]);
                }
            }
        }

        vector<bool>ans;

        for(auto &q : qs){
            int u = q[0];
            int v=q[1];

            ans.push_back(reachable[u][v]);
        }
        
        return ans;
    }
};