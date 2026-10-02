class Solution {
public:
    string getHint(string secret, string guess) {

        int bulls = 0;
        
        int cows = 0;

        vector<int>sf(10,0);
        vector<int>sg(10,0);


        for(int i = 0; i < secret.size();i++){
            if(secret[i]==guess[i])
               bulls++;
        

        
        if(secret[i] != guess[i]){
            sf[secret[i]-'0']++;
            sg[guess[i]-'0']++;
        }
        }

        for(int d = 0; d <=9;d++){
            cows+= min(sf[d],sg[d]);
        }

        return to_string(bulls)+"A"+to_string(cows)+"B";
        
    }
};