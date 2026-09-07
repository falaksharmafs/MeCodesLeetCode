class Solution {
public:
    int t[201][20001];
    bool solve(int i , int target,vector<int>& nums){
        if(target == 0){
            return true;
        }
        if(i < 0){
            return false;
        }
        if(t[i][target] != -1){
            return t[i][target];
        }
        bool nottake = solve(i-1,target,nums);
        int take = false;

        if(nums[i] <= target){
            take = solve(i-1,target-nums[i],nums);
        }
        return t[i][target] =
            take || nottake;

    }

    bool canPartition(vector<int>& nums) {
        memset(t,-1,sizeof(t));

        int sum = 0;

        for(int x : nums){
            sum += x;
        }

        if(sum % 2 != 0){
            return false;
        }
        int target = sum /2;

        return solve(nums.size()-1,target,nums);
    }
};