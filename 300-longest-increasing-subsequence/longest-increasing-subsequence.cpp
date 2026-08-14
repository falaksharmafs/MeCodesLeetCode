class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int>result;


        for(int i = 0 ; i < nums.size();i++){
            int pos = lower_bound(begin(result),end(result),nums[i]) - begin(result);

            if(pos==(result.size())){
                result.push_back(nums[i]);
            }
            else{
                result[pos]=nums[i];
            }
        }
        return result.size();
        
    }
};