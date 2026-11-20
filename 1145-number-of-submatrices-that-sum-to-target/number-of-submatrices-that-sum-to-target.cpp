class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        ///fisrt we will be going for row wise cumulative sum

        /////meaning ki pehle hum vertically neccehe jaake dekh rahe hai kiska kya sum bana

        for(int row = 0; row < rows;row++){
            for(int col = 1; col < cols; col++){
                matrix[row][col] += matrix[row][col-1];
            }
        }

        // now gping along the vertical ladder to see kitne subarray sum kar rahe hai 'k'

        int result = 0;

        for(int startc =0; startc < cols;startc++){
            for(int i =startc;i<cols;i++){
                unordered_map<int,int>mp;
                mp.insert({0,1});
                int cumsum = 0;

                for(int row = 0;  row < rows; row++){
                    cumsum += matrix[row][i] - (startc > 0 ? matrix[row][startc-1]:0);

                    if(mp.find(cumsum - target) != mp.end()){
                        result += mp[cumsum - target];
                    }

                    mp[cumsum]++;
                }                
            }
        }

        return result;
        
    }
};