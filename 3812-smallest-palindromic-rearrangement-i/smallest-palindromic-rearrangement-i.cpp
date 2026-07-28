class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int>freq(26,0);

        for(char ch: s){
            freq[ch - 'a']++;
        }

        string left = "";
        string right = "";
        string middle = "";

        for(int i = 0 ; i < 26 ; i++){
            left.append(freq[i]/2,char(i+'a'));

            if(freq[i]%2==1){
                middle = char( i + 'a');
            }

            right = left;
            reverse(right.begin(),right.end());

        }

        return left + middle + right;
        
    }
};