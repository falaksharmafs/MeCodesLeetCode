class Solution {
public:
    bool isVowel(char & ch) {
        return ( ch == 'a'|| ch =='e' || ch =='i' || ch =='o' || ch == 'u' || ch == 'A'|| ch =='E' || ch =='I' || ch =='O' || ch == 'U');
    }
    bool halvesAreAlike(string s) {

        int los = s.length();

        int mid = los/2;
        int i = 0 , j = mid;

        int cR = 0;
        int cL = 0;


        while(i  < los/2 && j < los) {
            if(isVowel(s[i])) cL++;
            if(isVowel (s[j])) cR++;
            i++;
            j++;
        }

        return cL == cR;
       



        
    }
};