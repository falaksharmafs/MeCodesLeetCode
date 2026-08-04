class Solution {
public:
    int M = 1e9+7;
    int numberOfWays(string corridor) {

        int n = corridor.size();

        vector<int>posseats;

        for(int i = 0; i < n; i++){

            if(corridor[i]=='S'){
                posseats.push_back(i);
            }
        }

        if(posseats.size()%2!=0||posseats.size() == 0){
            return 0;
        }

        long long result = 1;

        int prev = posseats[1];


        for(int i = 2 ; i < posseats.size(); i+=2){

            int l = posseats[i]-prev;

            result = (result*l)%M;
            prev = posseats[i+1];
        }

        return result;
        
    }
};