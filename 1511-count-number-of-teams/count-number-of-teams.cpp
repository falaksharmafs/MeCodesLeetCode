class Solution {
public:
    int numTeams(vector<int>& rating) {

        int n = rating.size();

        int teams = 0;


        for(int j = 1; j < n -1 ; j ++){
            int countSL =0;
            int countLR =0;
            int countSR =0;
            int countLL =0;


            for(int i = 0 ; i < j ; i++){
                if(rating[i] < rating[j]){
                    countSL++;
                }else if(rating[i]>rating[j]){
                    countLL++;
                }
            }

            for(int k = j+1 ; k < n ; k++){
                if(rating[k] < rating[j]){
                    countSR++;
                }else if(rating[k]>rating[j]){
                    countLR++;
                }
            }

            teams+= (countLL * countSR) + (countSL * countLR);




        }

        return teams;
        
    }
};