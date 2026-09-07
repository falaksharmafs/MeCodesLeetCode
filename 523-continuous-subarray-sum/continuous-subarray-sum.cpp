class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        mp[0]=-1;

        int sum = 0;
        int ans = 0;

        for(int x = 0 ;  x < nums.size(); x++){
            sum += nums[x];

            int rem = sum % k;

            if(mp.count(rem)){
                if(x-mp[rem] >= 2){
                    return true;
                }
            }
            else{
                mp[rem] = x;
            }
        }
        return false;

    }
};