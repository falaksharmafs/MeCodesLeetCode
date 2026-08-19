class Solution {
public:
    int n;
    int t[1001][1001];
    bool isPred(string & i,string & p){
        int M = i.length();
        int N = p.length();

        if( N>=M || M-N != 1){
            return false;
        }
        int k = 0,j= 0;

        while(k < N && j < M){
            if(p[k]==i[j])
              k++;
            j++;  
        }
        return k == N;
        
    }
    static bool myfunc(string &word1, string &word2){
        return word1.length()< word2.length();
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(begin(words),end(words),myfunc);

        vector<int> t(n,1);
        int maxL = 1;

        for(int k= 0; k < n ; k++){
            for(int j = 0 ; j < k ; j++){

                if(isPred(words[k],words[j])){
                    t[k]= max(t[k],t[j]+1);
                    maxL = max(maxL,t[k]);
                }
            }
        }

        return maxL;        
    }
};