class Solution {
public:
    int w[1001][1001];
    int solve(string &s,string &t,int i, int j){   
        if(j==t.size()){
            return 1;
        }


        if(i>=s.size()){
            return 0;
        }

        if(w[i][j] != -1){
            return w[i][j];
        }


        if(s[i]==t[j]){
            int take = solve(s,t,i+1,j+1);
            int skip = solve(s,t,i+1,j);

            return w[i][j]=take+skip;
        }

        return w[i][j]=solve(s,t,i+1,j);
    }
    int numDistinct(string s, string t) {

        memset(w,-1,sizeof(w));
        return solve(s,t,0,0);
    }
};