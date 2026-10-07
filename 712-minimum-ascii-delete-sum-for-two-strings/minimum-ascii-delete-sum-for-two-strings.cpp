class Solution {
public:
    int t[1001][1001];

    int solve(string &s1, string &s2,int i,int j){
        if(i == s1.size()){
            int sum = 0;
            for(int k = j; k< s2.size();k++){
                sum += s2[k];

            }
            return sum;
        }

        if(j == s2.size()){
            int sum = 0;

            for(int k = i; k < s1.size();k++){
                sum+=s1[k];
            }
            return sum;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(s1[i]==s2[j]){
            return t[i][j]= solve(s1,s2,i+1,j+1);
        }

        int dell = s1[i]+solve(s1,s2,i+1,j);

        int delll = s2[j]+solve(s1,s2,i,j+1);


        return t[i][j] = min(dell,delll);
    }

    int minimumDeleteSum(string s1, string s2) {

        memset(t,-1,sizeof(t));
        return solve(s1,s2,0,0);
    }
};