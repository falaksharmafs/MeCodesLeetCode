class Solution {
public:
    vector<vector<int>> memo;
    int solve(vector<int> &nums, int i , int j){
        if(i==j)
          return nums[i];
        if(memo[i][j] != -1)
           return memo[i][j];
        int takeLeft = nums[i]-solve(nums , i+1, j);
        int takeRight = nums[j]-solve(nums,i,j-1);
        return memo[i][j]= max(takeLeft,takeRight);     
    }
    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();
        memo.assign(n, vector<int>(n,-1));

        return solve(nums,0,n-1) >= 0;
        
    }
};