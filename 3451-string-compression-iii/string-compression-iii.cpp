class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        string comp = "";

        int i = 0;

        while (i < n) {
            char ch = word[i];
            int count = 0;

            while (i < n && word[i] == ch && count < 9) {
                count++;
                i++;
            }

            comp += to_string(count);
            comp += ch;
        }

        return comp;
    }
};