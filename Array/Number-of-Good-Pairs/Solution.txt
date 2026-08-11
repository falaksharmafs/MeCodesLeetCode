class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;

        unordered_map<int,int>mp;

        for(int i = 0; i < nums.size();i++){
            ans += mp[nums[i]];

            mp[nums[i]]++;
        }
        return ans;
        
    }
};