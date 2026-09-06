class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();
        vector<int>freq(n+1);

        for(int x : nums){
            freq[x]++;
        }

        int duplicate = -1;
        int missed = -1;

        for(int i = 0 ; i <= n ; i++){
            if(freq[i] == 2)
              duplicate = i;
            if(freq[i]==0)
               missed = i;
        }

        return {duplicate,missed};
    }
};