class Solution {
public:
    int findMin(vector<int>& nums) {

        int minn = nums[0];

        for(int x : nums){
            minn = min(x,minn);
        }

        return minn;
        
    }
};