class Solution {
public:
    vector<int> grayCode(int n) {

        vector<int>result;
        result.push_back(0);

        for(int i = 0; i < n; i++){
            int mask = 1<<i;
            int n = result.size();

            for(int j = n -1; j >= 0; j--){
                result.push_back(result[j]|mask);
            }
        }
        return result;
    }    
};