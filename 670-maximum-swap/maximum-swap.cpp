class Solution {
public:
    int maximumSwap(int num) {

        string s = to_string(num);
        string sorted = s;

        sort(sorted.begin(), sorted.end(), greater<char>());

        int n = s.length();

        for (int i = 0; i < n; i++) {

            if (s[i] != sorted[i]) {

                int j = n - 1;

                while (s[j] != sorted[i]) {
                    j--;
                }

                swap(s[i], s[j]);
                break;
            }
        }

        return stoi(s);
    }
};