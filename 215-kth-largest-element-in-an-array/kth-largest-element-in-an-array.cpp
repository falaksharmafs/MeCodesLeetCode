class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));

        int n = nums.size();

        return nums[n-k];


    }
};