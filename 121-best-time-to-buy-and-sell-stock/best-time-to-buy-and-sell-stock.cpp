class Solution {
public:
    int maxProfit(vector<int>& price) {
        int mini = price[0];
        int profit = 0;

        for(int i = 1; i < price.size();i++){
            mini = min(mini,price[i]);
            profit = max(profit,price[i]-mini);
        }

        return profit;
    }
};