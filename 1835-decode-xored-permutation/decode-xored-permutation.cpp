class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;

        int total = 0;

        for(int i = 1; i <= n; i++) {
            total ^= i;
        }

        for(int i = 1; i < n - 1; i += 2) {
            total ^= encoded[i];
        }

        vector<int> ans(n);

        ans[0] = total;

        for(int i = 0; i < n - 1; i++) {
            ans[i + 1] = ans[i] ^ encoded[i];
        }

        return ans;
    }
};