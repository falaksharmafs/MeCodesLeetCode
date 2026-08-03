class Solution {
public:
    bool closeStrings(string w1, string w2) {
        int m = w1.length();
        int n = w2.length();

        if(m != n){
            return false;
        }

        vector<int>f1(26,0);
        vector<int>f2(26,0);

        for(int i = 0; i < m ; i++){
            char ch1 = w1[i];
            char ch2 = w2[i];

            int idx1 = ch1-'a';
            f1[idx1]++;

            int idx2 = ch2-'a';
            f2[idx2]++;
        }

        for(int i = 0 ; i < 26 ;i++){
            if(f1[i] !=0 && f2[i]!=0) continue;

            if(f1[i] ==0 && f2[i]==0) continue;

            return false;
        }

        sort(begin(f1),end(f1));
        sort(begin(f2),end(f2));

        return f1==f2;
        
    }
};