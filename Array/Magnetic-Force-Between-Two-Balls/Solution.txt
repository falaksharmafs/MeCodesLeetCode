class Solution {
public:
    bool placepossible(int force ,vector<int> &position,int m){
        int prev = position[0];
        int countBalls=1;

        for(int i = 1; i<position.size();i++){

            int curr = position[i];

            if(curr - prev >= force){
                countBalls++;
                prev = curr;
            }

            if(countBalls == m)
              break;

        }
        return countBalls == m;
    }
    int maxDistance(vector<int>& position, int m) {

        int n = position.size();
        sort(begin(position),end(position));

        int minPos=1;
        int maxPos=position[n-1]-position[0];
        int result =0;

        while(minPos<=maxPos){
            int mid = minPos + (maxPos-minPos)/2;

            if(placepossible(mid,position,m)){
                result = mid;
                minPos = mid+1;
            }else{
                maxPos=mid-1;
            }


        }
        return result;

        
        
    }
};