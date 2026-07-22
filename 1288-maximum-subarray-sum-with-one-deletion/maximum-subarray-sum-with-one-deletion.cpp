class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int n = arr.size();

        vector<int> keep(n);
        vector<int> del(n);

        keep[0] = arr[0];
        del[0] = arr[0];

        int ans = arr[0];

        for(int i = 1; i < n; i++) {

            keep[i] = max(arr[i], keep[i - 1] + arr[i]);

            del[i] = max(keep[i - 1], del[i - 1] + arr[i]);

            ans = max(ans, max(keep[i], del[i]));
        }

        return ans;
    }
};