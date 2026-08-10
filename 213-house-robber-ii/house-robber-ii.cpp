class Solution {
public:
    int t[101];
    int solve (vector<int> &nums,int i , int n){
        if(i>n)
          return 0;
        if(t[i]!=-1)
         return t[i];
        int skip = solve(nums,i+1,n);
        int steal = solve(nums,i+2,n) + nums[i];

        return t[i] = max(steal,skip);    
    }
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);

        }
        memset(t , -1 ,sizeof(t));

        int take0 = solve(nums,0,n-2);

        memset(t , -1  ,sizeof(t));

        int take1 = solve(nums,1,n-1);
        
        return max(take0,take1);

        
    }
};