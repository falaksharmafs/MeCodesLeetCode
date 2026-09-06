class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();

        vector<int>prefix(n+1,0);

        for(int i = 0; i < n ;i++){
            prefix[i+1] = prefix[i] ^arr[i];
        }
        
        vector<int>ans;

        for(auto &q : queries){
            int L = q[0];
            int R =q[1];

            ans.push_back(prefix[R+1] ^ prefix[L]);
        }

        return ans;
    }
};