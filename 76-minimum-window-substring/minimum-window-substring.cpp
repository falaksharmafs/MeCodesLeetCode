class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> need;

        for(char c : t)
            need[c]++;

        unordered_map<char,int> window;

        int left = 0;

        int required = need.size();
        int formed = 0;

        int bestLen = INT_MAX;
        int bestLeft = 0;

        for(int right = 0; right < s.size(); right++) {

            char c = s[right];

            window[c]++;

            if(need.count(c) && window[c] == need[c])
                formed++;

            while(formed == required) {


                if(right - left + 1 < bestLen) {

                    bestLen = right - left + 1;
                    bestLeft = left;
                }

                char removeChar = s[left];

                window[removeChar]--;

                if(need.count(removeChar) &&
                   window[removeChar] < need[removeChar]) {

                    formed--;
                }

                left++;
            }
        }

        if(bestLen == INT_MAX)
            return "";

        return s.substr(bestLeft, bestLen);
    }
};