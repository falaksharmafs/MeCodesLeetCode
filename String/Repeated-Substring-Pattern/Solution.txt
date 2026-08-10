class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        int n = s.size();

        for (int j = 1; j < n; j++) {

            if (n % j != 0)
                continue;

            int i = 0;
            int k = j;

            bool valid = true;

            while (k < n) {

                if (s[i] != s[k]) {
                    valid = false;
                    break;
                }

                i++;

                if (i == j)
                    i = 0;

                k++;
            }

            if (valid)
                return true;
        }

        return false;
    }
};