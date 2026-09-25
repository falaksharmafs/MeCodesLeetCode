class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int pro = 1;
        int ans = 0;

        while(right < nums.size()){
            pro *= nums[right];

            while(pro >= k && left <= right){
                pro /= nums[left];
                left++;
            }
            ans += right-left+1;
            right++;
        }
        
        return ans;
    }
};