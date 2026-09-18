class Solution {
public:
    int t[5001][2];
    int solve(int i , int buy , vector<int>& prices){
        if(i >= prices.size()){
            return 0;
        }
        if(t[i][buy]!= -1){
            return t[i][buy];
        }
        int ans = 0;

        if(buy){
            int take = -prices[i] + solve(i+1,0,prices);

            int skip = solve(i+1,1,prices);

            ans = max(take,skip);
        }
        else{
            int sell = prices[i] + solve(i+2,1,prices);

            int skip = solve(i+1,0,prices);

            ans = max(sell,skip);
        }
        return t[i][buy] = ans;
    }
    int maxProfit(vector<int>& prices) {

        memset(t,-1,sizeof(t));
        return solve(0,1,prices);
    }
};