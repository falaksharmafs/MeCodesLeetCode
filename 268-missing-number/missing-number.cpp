class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        long expected = (long) n * (n+1)/2 ;
        long actual = 0;

        for (int x : nums) {
            actual +=x;
        }

        return (int)(expected - actual);

        
    }
};