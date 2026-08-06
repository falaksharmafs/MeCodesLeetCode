class Solution {
public:
    int specialArray(vector<int>& nums) {

        int count = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int x = 0; x <= n ; x++){

            int idx = lower_bound(nums.begin(),nums.end(),x)- nums.begin();

            count = n - idx;

            if(count==x)
             return x;


        }
        return -1;
        
    }
};