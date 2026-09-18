class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> t(n, vector<int>(2, -1));

        auto solve = [&](auto& self, int i, int prevsw) -> int {
            if (i == n) {
                return 0;
            }
            if (t[i][prevsw] != -1) {
                return t[i][prevsw];
            }

            int prev1 = nums1[i - 1];
            int prev2 = nums2[i - 1];

            if (prevsw) {
                swap(prev1, prev2);
            }

            int ans = INT_MAX;

            if (nums1[i] > prev1 && nums2[i] > prev2) {
                ans = min(ans, self(self, i + 1, 0));
            }

            if (nums2[i] > prev1 && nums1[i] > prev2) {
                ans = min(ans, 1 + self(self, i + 1, 1));
            }

            return t[i][prevsw] = ans;
        };

        int s1 = solve(solve, 1, 0);         
        int s2 = 1 + solve(solve, 1, 1);     

        return min(s1, s2);
    }
};