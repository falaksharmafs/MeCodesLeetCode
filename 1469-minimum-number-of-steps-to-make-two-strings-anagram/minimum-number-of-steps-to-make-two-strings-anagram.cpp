class Solution {
public:
    int minSteps(string s, string t) {

        int n = s.length();



        int mps[26] ={0};

        int mpt[26]={0};


        for(int i = 0; i < n ; i++){

            mps[s[i]-'a']++;
            mpt[t[i]-'a']++;

        }

        int result = 0;

        for(int i = 0; i<26; i++){
            if(mps[i]>mpt[i]){

                result += mps[i]-mpt[i];
            }


        }

        return result;
        
    }
};