class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int v : nums) freq[v]++;

        vector<int> ans;
        for (auto& [val, cnt] : freq)
            if (cnt > n/3) ans.push_back(val);
        return ans;
    }
};