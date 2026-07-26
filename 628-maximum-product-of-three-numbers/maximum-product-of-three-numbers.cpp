class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums),end(nums));
        if ((nums[n-1] * nums[n-2] * nums[n-3]) > (nums[0] * nums[1] * nums[n-1])){

        return nums[n-1] * nums[n-2] * nums[n-3];

        }else {
            return nums[0] * nums[1] * nums[n-1];
        }
        
    }
};