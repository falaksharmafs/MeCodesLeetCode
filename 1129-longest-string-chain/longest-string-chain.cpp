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
    int lis(vector<string>& words , int i, int p){
        if(i>=n){
            return 0;
        }
        if(p != -1 && t[i][p] != -1){
            return t[i][p];
        }
        int taken = 0;

        if(p == -1 || isPred(words[i],words[p])){
            taken = 1 + lis(words,i+1,i);
        }
        int skip = lis(words,i+1,p);
        if(p != -1)
           t[i][p]= max(taken,skip);
        return max(skip,taken);
    }
    int longestStrChain(vector<string>& words) {

        memset(t,-1,sizeof(t));
        n = words.size();
        sort(begin(words),end(words),myfunc);

        return lis(words,0,-1);        
    }
};