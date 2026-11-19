class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>freq;

        int l =0;
        long long sum =0;
        long long ans =0;
        for(int r = 0; r < nums.size();r++){
            sum += nums[r];
            freq[nums[r]]++;

            if(r-l+1 > k){
                sum -= nums[l];
                freq[nums[l]]--;
            

            if(freq[nums[l]]==0){
                freq.erase(nums[l]);

            }
            l++;
            }
            if(r-l+1 == k && freq.size()==k){
                ans = max(sum,ans);
            }

        }

        return ans;
            
        
    }
};