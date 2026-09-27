class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0;
        int right = 0;

        vector<int> freqP(26, 0);
        vector<int> freqWindow(26, 0);
        vector<int> ans;

        for (char c : p) {
            freqP[c - 'a']++;
        }

        while (right < s.size()) {
            freqWindow[s[right] - 'a']++;

            if (right - left + 1 == p.size()) {

                if (freqP == freqWindow) {
                    ans.push_back(left);
                }

                freqWindow[s[left] - 'a']--;
                left++;
            }

            right++;
        }

        return ans;
    }
};