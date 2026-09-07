class Solution {
public:
    int m,n;
    int t[1001][1001];

    int solve(int i,int j ,vector<vector<int>>& dungeon){
        if(i>=m||i<0||j>=n||j<0){
            return INT_MAX;
        }
        if(i==m-1 && j==n-1)
           return max(1,1-dungeon[i][j]);

        if(t[i][j] != -1){
            return t[i][j];
        }

        int down = solve(i+1,j,dungeon);
        int right = solve(i,j+1,dungeon);

        int need = min(down,right) - dungeon[i][j];

        return t[i][j] = max(1,need);
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        memset(t,-1,sizeof(t));

        m = dungeon.size();
        n = dungeon[0].size();

        return solve(0,0,dungeon);
    }
};