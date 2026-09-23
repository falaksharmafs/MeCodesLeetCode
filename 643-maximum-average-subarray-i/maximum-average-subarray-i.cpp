class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int maxsum= INT_MIN;

        while(right < nums.size()){
            sum += nums[right];

            if(right-left+1 == k){
                maxsum = max(sum,maxsum);

                sum-=nums[left];
                left++;
            }
            right++;
        }
        return (double)maxsum/k;
    }
};