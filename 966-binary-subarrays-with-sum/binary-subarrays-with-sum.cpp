class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;

        mp.insert({0,1});

        int n = nums.size();

        int r = 0;
        int cs = 0;

        for(int i = 0; i < n ;i++){
            cs += nums[i];
            if(mp.find(cs-goal) != mp.end()){
                r += mp[cs-goal];
            }
            mp[cs]++;
        }

        return r;
    }
};