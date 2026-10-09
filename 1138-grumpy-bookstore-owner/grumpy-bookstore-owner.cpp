class Solution {
public:
    int maxSatisfied(vector<int>& cu, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();
        int satisfied = 0;

        for(int i = 0; i < n ;i++){
            if(grumpy[i]==0){
                satisfied += cu[i];
            }
        }

        int windowgain = 0;
        

        for(int i = 0; i < minutes;i++){
            if(grumpy[i]==1){
                windowgain += cu[i];
            }
        }

        int maxwindowgain = windowgain;

        for(int i = minutes;i< n;i++){
            if(grumpy[i]==1){
                windowgain += cu[i];
            }

            if(grumpy[i-minutes]==1){
                windowgain -= cu[i-minutes];
            }

            maxwindowgain = max(maxwindowgain,windowgain);
        }
        return satisfied+maxwindowgain;
    }
};