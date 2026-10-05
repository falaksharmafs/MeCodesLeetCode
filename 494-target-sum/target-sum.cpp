class Solution {
public:
    int t[21][40001];

    int solve(vector<int>& nums, int target, int idx, int sum) {
        if(idx == nums.size())
            return sum == target;

        if(t[idx][sum + 20000] != -1)
            return t[idx][sum + 20000];

        int plus = solve(nums, target, idx + 1, sum + nums[idx]);

        int minus = solve(nums, target, idx + 1, sum - nums[idx]);

        return t[idx][sum + 20000] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(t, -1, sizeof(t));
        return solve(nums, target, 0, 0);
    }
};