class Solution {
public:
    int maxProduct(vector<int>& a) {

        int currmax = a[0];
        int currmin = a[0];
        int ans = a[0];

        for(int i = 1; i < a.size(); i++) {

            int minp = currmin;
            int maxp = currmax;

            currmax = max(a[i], max(a[i] * maxp, a[i] * minp));

            currmin = min(a[i], min(a[i] * maxp, a[i] * minp));

            ans = max(ans, currmax);
        }

        return ans;
    }
};