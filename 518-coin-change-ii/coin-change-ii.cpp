class Solution {
public:
    int t[301][5001];
    int solve(vector<int>& coins,int idx,int amount){
        if(amount == 0)
          return 1;
         
        if(idx == coins.size()||amount < 0){
            return 0;
        }  
        if(t[idx][amount] != -1){
           return t[idx][amount];
        } 

        int take = solve(coins,idx,amount-coins[idx]);
        int skip = solve(coins,idx+1,amount);

        return t[idx][amount]= take+skip;
    }
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        return solve(coins,0,amount);
    }
};