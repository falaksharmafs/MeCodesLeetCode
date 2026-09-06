class Solution {
public:
    int maxCoins(vector<int>& piles) {

        int n = piles.size();

        sort(begin(piles),end(piles));

        int l = 0;
        int r = n-1;

        int ans = 0;

        while(l < r){

            r--;

            ans += piles[r];
            r--;

            l++;

        }

        return ans;
        
    }
};