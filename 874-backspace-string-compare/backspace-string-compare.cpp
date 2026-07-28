class Solution {
public:
    bool backspaceCompare(string s, string t) {

        int m = s.length();

        int n = t.length();


        int i = m-1;
        int j = n-1;

        int skipi = 0;
        int skipj = 0;

        while(i>=0 || j >=0){

            while(i >=0){
                if(s[i] == '#'){
                    skipi++;
                    i--;
                }else if(skipi > 0){
                    skipi--;
                    i--;
                }else{
                    break;
                }
            }

            while(j >=0){
                if(t[j] == '#'){
                    skipj++;
                    j--;
                }else if(skipj > 0){
                    skipj--;
                    j--;
                }else{
                    break;
                }
            }

            char first = i < 0 ? '$' : s[i];
            char second = j < 0 ? '$' : t[j];

            if(first != second)
              return false;
            i--;
            j--;  
        }
        return true;
    }
};