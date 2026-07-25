class Solution {
public:
    int maxProduct(int n) {

        vector<int> digits;

        while(n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        int largest = 0;
        int secondLargest = 0;

        for(int digit : digits) {

            if(digit > largest) {
                secondLargest = largest;
                largest = digit;
            }
            else if(digit > secondLargest) {
                secondLargest = digit;
            }
        }

        return largest * secondLargest;
    }
};