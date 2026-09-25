class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int currZeros = 0;
        int currSize = 0;
        int maxSize = 0;

        while (right < nums.size()) {

            if (nums[right] == 0) {
                currZeros++;
            }

            while (currZeros > k) {
                if (nums[left] == 0) {
                    currZeros--;
                }
                left++;
            }

            currSize = right - left + 1;
            maxSize = max(maxSize, currSize);

            right++;
        }

        return maxSize;
    }
};