class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        vector<int> freq(26, 0);

        for(char ch : chars){
            freq[ch - 'a']++;
        }

        int ans = 0;

        for(string word : words){

            vector<int> temp = freq;
            bool ok = true;

            for(char ch : word){

                if(temp[ch - 'a'] == 0){
                    ok = false;
                    break;
                }

                temp[ch - 'a']--;
            }

            if(ok)
                ans += word.length();
        }

        return ans;
    }
};