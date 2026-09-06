class Solution {
public:
    int maxCoins(vector<int>& piles) {

        int n = piles.size();

        sort(begin(piles),end(piles));

        int l = 0;
        int r = n-1;

        int ans = 0;

        for(int i = 0 ; i < n/3 ; i++){
            r--;
            l++;
            ans += piles[r];
            r--;
        }

        return ans;
        
    }
};