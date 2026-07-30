class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> deq;
        int ans = INT_MAX;

        for (int i = 0; i <= n; i++) {

            while (!deq.empty() && prefix[i] - prefix[deq.front()] >= k) {
                ans = min(ans, i - deq.front());
                deq.pop_front();
            }

            while (!deq.empty() && prefix[i] <= prefix[deq.back()]) {
                deq.pop_back();
            }

            deq.push_back(i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};