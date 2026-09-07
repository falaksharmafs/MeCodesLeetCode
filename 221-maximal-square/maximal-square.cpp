class Solution {
public:
    int t[301][301];
    int m,n;
    int solve(int i, int j ,vector<vector<char>>& matrix){

        if(i>=m || i<0 || j>=n || j<0){
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(matrix[i][j]=='0'){
            return t[i][j]=0;
        }

        int right = solve(i,j+1,matrix);
        int down = solve(i+1,j,matrix);
        int diagonal = solve(i+1,j+1,matrix);

        return t[i][j] = 1+ min({right,down,diagonal});

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        memset(t,-1,sizeof(t));

        int ans = 0;
        for(int i = 0 ; i < m ;i++){
            for(int j = 0; j < n ;j++){
                ans = max(ans,solve(i,j,matrix));
            }
        }
        return ans * ans;
    }
};