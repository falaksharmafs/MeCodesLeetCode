class Solution {
public:
    typedef long long ll;
    int maxSubArray(vector<int>& nums) {
        ll maxsum = nums[0];
        ll curr = nums[0];

        for(int i =1; i < nums.size();i++){
            curr = max((ll)nums[i],curr+nums[i]);
            maxsum = max((ll)curr,maxsum);
        }

        return maxsum;
        
    }
};