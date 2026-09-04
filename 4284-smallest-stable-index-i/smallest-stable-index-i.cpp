class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int maxx = nums[0];
            int minn = nums[i];

            
            for(int j = 0; j <= i; j++) {
                maxx = max(maxx, nums[j]);
            }

            
            for(int j = i; j < n; j++) {
                minn = min(minn, nums[j]);
            }

            if(maxx - minn <= k) {
                return i;
            }
        }

        return -1;
    }
};